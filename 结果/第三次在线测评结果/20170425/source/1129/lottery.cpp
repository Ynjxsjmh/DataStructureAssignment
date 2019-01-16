#include<iostream>
#include<cstdio>
#include<map>
#include<fstream>
using namespace std;

map<int,int> L;
int a[1001];

int main()
{
    ifstream in("lottery.in.txt");
    ofstream out("lottery.out.txt");
    int n,x;
    in>>n;
    for(int i=0;i<7;i++)
    {
        in>>x;
        L[x]++;
    }
    int Count;
    for(int j=0;j<n;j++)
    {
        Count=0;
        for(int k=0;k<7;k++)
           {
            in>>x;
           if(L[x])Count++;
           }
        a[Count]++;
    }
    for(int i=7;i>0;i--)
        out<<a[i]<<" ";
        out<<endl;

}
