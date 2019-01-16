//
//  main.cpp
//  Walmart彩票
//
//  Created by Rachel on 2017/4/25.
//  Copyright © 2017年 Rachel. All rights reserved.
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

class Lottery{
    int Number[7];
    int Prize[7];
public:
    Lottery(){for(int i=0;i<7;i++) Prize[i]=0;};
    void Check(int a[]);
    void SetNumber(int a[]);
    void Out(){
        int i=0;
        //for(i=0;i<7;i++)cout<<Number[i]<<" ";
        //cout<<endl;
        for(i=0;i<7;i++)cout<<Prize[i]<<" ";
        cout<<endl;
    }
};

void Lottery::Check(int a[7]){
    int i=0,j=0,cou=0;
    for(i=0;i<7;i++) for(j=0;j<7;j++) if(Number[i]==a[j]) cou++;
    if(cou)Prize[7-cou]++;
};

void Lottery::SetNumber(int a[7]){
    for(int i=0;i<7;i++) Number[i]=a[i];
}

int main(int argc, const char * argv[]) {
    int Answer[7],i=0,Ticket[7],t;
    Lottery a;
    cin>>t;
    
    for(i=0;i<7;i++){cin>>Answer[i];}
    a.SetNumber(Answer);//设置模版a
    while(t){
        for(i=0;i<7;i++) cin>>Ticket[i];
        a.Check(Ticket);
        t--;
    }
    a.Out();
    return 0;
}
/*
2
23 1 11 14 19 17 18
12 8 9 23 1 16 7
11 7 10 21 2 9 31
*/

