#include<iostream>
#include<cmath>
#include<stdio.h>

using namespace std;

const int m=10001;

struct Point{int a[m];int b[m];int c[m];};
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("circle.in","r");
    fp2=fopen("circle.out","w");
    int d[m];
    struct Point t;
    int Count=0;
    int num=0;
    int n,x;
    fscanf(fp1,"%d",&n);//cin>>n;
    for(int i=1;i<=n;i++)
    {
       fscanf(fp2,"%d %d %d",&t.a[i],&t.b[i],&t.c[i]); //cin>>t.a[i]>>t.b[i]>>t.c[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(sqrt((t.a[i]-t.a[j])*(t.a[i]-t.a[j])+(t.b[i]-t.b[j])*(t.b[i]-t.b[j]))<=(t.c[i]+t.c[j]))
            Count++;
        }
        d[i]=Count;
        Count=0;
    }
        x=d[1];
        for(int j=1;j<=n;j++)// 对特殊情况的补充
        {
            if(d[j]>0)num++;
        }
        if(num==n-1)x=n-1;
        else
        {for(int i=2;i<=n;i++)
            {if(d[i]>x) x=d[i];}}
    fprintf(fp2,"%d",n-x);//cout<<n-x<<endl;
    fclose(fp1);
    fclose(fp2);
}
