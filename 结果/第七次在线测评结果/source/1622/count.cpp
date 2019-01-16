#include<stdio.h>
#define max 0x3f3f3f3f
qsort(int  *a,int m,int n)
{
    int i,j;
    int   k,wo;
    if(m>=n)
          return 0;
    i=m;
    j=n+1;
    k=a[m];
    while(i<j)
    {
        i++;
        while(a[i]<k)
        {
            i++;
        }
        j--;
        while(a[j]>k)
        {
            j=j-1;

        }
        if(i<j)
        {
            wo=a[i];
            a[i]=a[j];
            a[j]=wo;
        }
    }
    wo=a[m];
    a[m]=a[j];
    a[j]=wo;
    qsort(a,m,j-1);
    qsort(a,j+1,n);
}
int main()
{
     freopen("count.in","r",stdin);
     freopen("count.out","w",stdout);
    int a[50005];
    int n,i,j,count;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n]=max;
    qsort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        count=1;
        j=i+1;
        while(a[i]==a[j])
        {
            j++;
            count++;
        }
        printf("%d %d\n",a[i],count);
        i=j-1;

    }

}
