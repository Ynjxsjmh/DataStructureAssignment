#include <fstream>
#include<iostream>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("lottery.in");
ofstream fout("lottery.out");
int main()
{
    int n,m;
    cin>>n;
    int a[7],b[7],c[7];
    for(int i=0;i<7;++i)
    {
        cin>>a[i];
        c[i]=0;
    }
    while(n>0)
    {
        m=0;
        for(int i=0;i<7;++i)
            cin>>b[i];
        for(int i=0;i<7;++i)
            for(int j=0;j<7;++j)
            if(b[j]==a[i]) m++;
        ++c[m];
        --n;

    }
     for(int i=6;i>=1;--i)
            cout<<c[i]<<" ";
}
