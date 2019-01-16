#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include <set>
const int nmax=7010;
double x[nmax],y[nmax],r[nmax],pre[nmax];

int findroot(int x)
{
    int r=x;
    while(pre[r] != r)
    {
        r=pre[r];
    }
    int i=x, j;
    while ( i!= r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}

void join(int x,int y)
{
    int xr=findroot(x);
    int yr=findroot(y);
    if(xr!=yr)
        pre[yr]=xr;
}

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w" , stdout);
    int n;
    double a,b,c;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            pre[i]=i;
        for(int i=1; i<=n; i++)
        {
            cin>>a>>b>>c;
            x[i]=a; y[i]=b; r[i]=c;
            if(i==1) {  x[1]=a; y[1]=b; r[1]=c; pre[1]=1; }
            for(int j=1; j<i; j++)
            {
                if(   ( (x[j]-a)*(x[j]-a)  +  (y[j]-b)*(y[j]-b) )  <= ( (r[j]+c)*(r[j]+c) ) )
                    join(i,j);
            }
        }
        set<int> se;
        for(int i=1; i<=n; i++)
        {
            se.insert(findroot(i));
        }
        cout<<se.size()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
