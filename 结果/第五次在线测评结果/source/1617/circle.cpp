#include<stdio.h>
#include<stdlib.h>
typedef struct acircle
{
        long long x,y,r;
}cir;

int main()
{
        freopen("circle.in","r",stdin);
        freopen("circle.out","w",stdout);
        long long n,ctr=1;
        scanf("%d",&n);
        cir* c=(cir*)malloc(n*sizeof(cir));
        for(long long i=0;i<n;i++)
        {
                scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);
        }
        for(long long i=0;i<n;i++)
        {
                for(long long j=i+1;j<n;j++)
                {
                        long long dx=c[i].x-c[j].x;
                        long long dy=c[i].y-c[j].y;
                        if((dx*dx+dy*dy)>((c[i].r+c[j].r)*(c[i].r+c[j].r)))
                        {

                                ctr++;
                        }
                }
        }
        printf("%d",ctr);
}
