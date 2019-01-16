#include <fstream>
#include<iostream>
#include<math.h>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("circle.in");
ofstream fout("circle.out");
bool Qie(long long int p)
{
    if(p<=0) return true;
    else return false;
}
int main()
{
    long long int n,m,p;
    bool flag;
    cin>>n;
    m=n;
    long long int x[n],y[n],r[n];
    for(int i=0;i<n;++i)
    {
        cin>>x[i]>>y[i]>>r[i];
    }
    for(int i=0;i<n-1;i++)
    {
         for(int j=i+1;j<n;j++)
        {
            p=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])-(r[i]+r[j])*(r[i]+r[j]);
            flag=Qie(p);
        }
        if(flag) m--;
    }
    cout<<m;
}
