#include"stdio.h"
#define N 7
main()
{
     int z,i,j=0,p;
     int a[N],b[N],c[N],d[N];
     freopen("lottery.in","r",stdin);
     freopen("lottery.out","w",stdout);
     scanf("%d",&z);
     for(i=0;i<N;i++)
     scanf("%d",&a[i]);
     for(i=0;i<N;i++)
    {
        c[i]=0;
        d[i]=0;
    }
     while(j<z)
     {
         for(i=0;i<N;i++)
         scanf("%d",&b[i]);
         for(i=0;i<N;i++)
         {
             for(p=0;p<N;p++)
             {
                 if(b[i]==a[p])
                    c[j]++;
             }
         }
         j++;
     }

     for(j=0;j<N;j++)
     {
         if(c[j]!=0)
         d[N-c[j]]=d[N-c[j]]+1;
     }
    for(i=0;i<N;i++)
    printf(" %d",d[i]);
       fclose(stdin);
       fclose(stdout);
}
