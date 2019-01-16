#include"stdio.h"
#include"math.h"
#define N 10000
main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i,j,n,l;
    int x[N],y[N],r[N];
    int a[N],b[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=i;
    i=0;
    l=0;
    while(i<n)
    {
       scanf("%d",&x[i]);
       scanf("%d",&y[i]);
       scanf("%d",&r[i]);
       i++;
    }
   for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
           if(sqrt((double)(x[j]-x[i])*(x[j]-x[i])+(double)(y[j]-y[i])*(y[j]-y[i]))<=r[i]+r[j])
                a[j]=a[i];
        }
    }
    b[0]=a[0];
    l=1;
    i=1;
    while(i<n)
    {
        for(j=0;j<l;j++){
             if(a[i]==b[j])
               i++;
        else{
            l++;
            b[l]=a[l];
        }
        }
    }
    printf("%d\n",l);
   fclose(stdin);
   fclose(stdout);
}
