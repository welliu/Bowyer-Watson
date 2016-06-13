#include "delaunay.h"
int main()
{
    ifstream infile("input.txt");//打开"input.txt"文件
    if (!infile)//判断文件是否正常打开
    {
        cout<<"Unable to input nodes!";
        exit(1);
    }
    string line;
    PointArray p;
    double xx,yy,zz;
    int nodeSize;
    /*
    for (int i=0;i<4;i++)//读入4外边框点
    {
        getline(infile,line);
        GetPoint(xx,yy,zz,line);
        Point tmp={xx,yy,zz};
        p.push_back(tmp);
    }
    */


    double boundary[2]={0,500};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            Point tmp={boundary[i],boundary[j],0.0};
            p.push_back(tmp);
        }
    }

    Delaunay MyMesh(p[0],p[1],p[2],p[3]);//实例化Delaunay类
    getline(infile,line);//读入节点数，用于后面循环
    char *cstr;
    cstr=new char[line.size()+1];
    strcpy(cstr,line.c_str());
    nodeSize=atoi(cstr);
    for (int i=0;i<nodeSize;i++)//读入每个节点的坐标
    {
        getline(infile,line);
        GetPoint(xx,yy,zz,line);
        MyMesh.AddPoint(xx,yy,zz);
    }
    infile.close();
    MyMesh.Delete_Frame();//删除外边框
    MyMesh.Boundary_Recover(203,466);
    MyMesh.Boundary_Recover(467,487);
    MyMesh.Boundary_Recover(488,511);
    MyMesh.Boundary_Recover(512,537);//以上都是恢复指定边界
    MyMesh.output();//将相应ANSYS命令流输出
    return 0;
}