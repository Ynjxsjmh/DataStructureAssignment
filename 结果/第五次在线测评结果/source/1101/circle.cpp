//
//  main.cpp
//  圆的划分
//
//  Created by Rachel on 2017/5/9.
//  Copyright © 2017年 Rachel. All rights reserved.
//

#include <iostream>
#include <stack>
#include <fstream>//
#define MaxSize 10000
using namespace std;
#define cin fin//
#define cout fout//

ifstream fin("circle.in");//
ofstream fout("circle.out");//

class circle{
private:
    int a,b,r;
public:
    circle(){};
    void Set(){
        int x,y,z;
        cin>>x>>y>>z;
        a=x;
        b=y;
        r=z;
    }
    int judge(circle c){
        int flag=0;
        if ((c.a-a)*(c.a-a)+(c.b-b)*(c.b-b)<=(c.r+r)*(c.r+r)) flag=1;
        return flag;
    }
};

int main(){
    int edge[1425][1425];
    int visited[MaxSize];
    circle *a[MaxSize];
    int cou=0,size;
    //int edge[MaxSize][MaxSize];
    cin>>size;
    
    for(int i=0;i<size;i++) for(int j=0;j<size;j++) edge[i][j]=0;//初始化二维数组
    for(int i=0;i<size;i++) visited[i]=0;//初始化visited数组
    for(int i=0;i<size;i++) {
        a[i]=new circle;
        a[i]->Set();
    }
    
    for(int i=0;i<size;i++) for(int j=i+1;j<size;j++) edge[i][j]=a[i]->judge(*a[j]);
    /*void Graph_MatrixDFS(int v)*/
    for(int j=0;j<size;j++){
        int v=j;
        if(visited[v]==0){
            stack<int> s;
            s.push(v);
            while(!s.empty()){
                visited[s.top()]=1;
                v=s.top();
                s.pop();
                for(int i=0;i<size;i++) if(visited[i]==0&&edge[v][i]!=0) s.push(i);
            }
            cou++;
        }
    }
    cout<<cou<<endl;
    return 0;
}
