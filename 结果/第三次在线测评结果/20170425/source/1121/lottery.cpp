# include<cstdio>
# include<iostream>
# include<iomanip>
using namespace std;
int object(int *p,int *q)
{
    int i,j,m=0;
    for(i=0;i<7;i++)
    {

        for(j=0;j<7;j++)
        {
            if(p[i]==q[j])
                m++;
        }
    }

    return m;
}
int main(void)
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int i;
    int n;
    int a[7];
    int b[10000];
    int c[1000]={0};
    int d[7]={0};
    cin>>n;
    for(i=0;i<7;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<(n*7);i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        c[i]=object(a,&b[i*7]);
      //  cout<<c[i];
    }
    for(i=0;i<n;i++)
    {
        if(c[i]==7)
            d[0]=1;
        if(c[i]==6)
            d[1]=1;
        if(c[i]==5)
            d[2]=1;
        if(c[i]==4)
            d[3]=1;
        if(c[i]==3)
            d[4]=1;
        if(c[i]==2)
            d[5]=1;
        if(c[i]==1)
            d[6]=1;
    }
    for(i=0;i<7;i++)
    {
        cout<<d[i]<<" ";
    }
     fclose(stdin);
    fclose(stdout);

}

