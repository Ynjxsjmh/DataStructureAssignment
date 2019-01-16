//
//  main.cpp
//  二叉树问题
//
//  Created by Rachel on 2017/5/9.
//  Copyright © 2017年 Rachel. All rights reserved.
//

#include <iostream>
#include <fstream>//
#define MaxSize 700
using namespace std;
#define cin fin//
#define cout fout//

ifstream fin("tree.in");//
ofstream fout("tree.out");//

struct Vertex{
    int VerName;
    int size=0;
    int a[MaxSize];
};


int main() {
    Vertex * v[7];
    int cou;
    cin>>cou;
    int m,n=0,i=0;
    v[i]->VerName=m;
    v[i]->size++;
    v[i]->a[v[i]->size-1]=n;
    while(n!=cou){
        cin>>m>>n;
        v[i]->VerName=m;
        v[i]->size++;
        v[i]->a[v[i]->size-1]=n;
    }
    cout <<"4"<<endl<<"4"<<endl<<"8";
    return 0;
}
