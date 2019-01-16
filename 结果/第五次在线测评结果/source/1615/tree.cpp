#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int nmax=110;
int pre[nmax],lef[nmax],righ[nmax],deep[nmax],width[nmax];


void coutdeep(int n)
{
    int dmax=-1;
    for(int i=1; i<=n; i++)
    {
        if(deep[i]>dmax)  dmax=deep[i];
    }
    cout<<dmax<<endl;
}

void coutwidth(int n)
{
    memset(width, 0, sizeof(width));
    for(int i=1; i<=n; i++)
    {
        width[ deep[i] ] ++;
    }
    int wmax=-1;
    for(int i=1; i<=n; i++)
    {
        if(width[i]>wmax) wmax=width[i];
    }
    cout<<wmax<<endl;
}

void coutdist(int n,int s, int e)
{
    int dis=0;
    if( deep[s]>=deep[e] )
    {
        dis= dis + 2*(deep[s]-deep[e]);
        for(int i=1; i<= (deep[s]-deep[e] ) ; i++ )
        {
            s=pre[s];
        }
    }
    if (deep[s]< deep[e] )
    {
        dis  = dis + deep[e]-deep[s];
        for(int i=1; i<= (deep[e]-deep[s] ) ; i++ )
        {
            e=pre[e];
        }
    }
    while(1)
    {
        if(s==e) { cout<<dis<<endl; break;}
        s=pre[s]; e=pre[e];
        dis += 3;
    }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=nmax-1; i++)
        {
           pre[i]=-1;
           lef[i]=-1;
           righ[i]=-1;
           deep[i]=-1;
           width[i]=-1;
        }
        width[1]=1; deep[1]=1; pre[1]=1;
        for(int i=1; i<=n-1; i++)
        {
            int f,s;
            cin>>f>>s;
            if(lef[f]==-1)  {  lef[f]=s;  deep[s]=deep[f]+1; }
            else             {  righ[f]=s; deep[s]=deep[f]+1; }
            pre[s]=f;
        }
        int s,e;
        cin>>s>>e;
        coutdeep(n);
        coutwidth(n);
        coutdist(n,s,e);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
