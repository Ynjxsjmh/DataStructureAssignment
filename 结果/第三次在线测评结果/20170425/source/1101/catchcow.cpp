//
//  main.cpp
//  捉牛
//
//  Created by Rachel on 2017/4/25.
//  Copyright © 2017�?Rachel. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
#include <fstream>

#define cin fin
#define cout fout
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");

int main(int argc, const char * argv[]) {
    queue<int>q;
    int a,b,cou=0,i=0;
    cin>>a>>b;
    q.push(a);
    while(a!=b){
        q.push(a+1);
        q.push(a-1);
        q.push(a*2);
        q.pop();
        a=q.front();
        cou++;
    }
    while(pow(3,i)<=cou){
        cou-=pow(3,i);
        i++;
    }
    cout<<i<<endl;
    return 0;
}
