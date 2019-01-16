#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int n;
int *a;
int *x;
void pri();
void Sort()
{
    int minv,k,t;
    for(int i=1;i<n;i++)
    {
      //  pri();
        //minv=a[i];
        t=i;
        //printf("minvi0=%d\n",minv);
        for(int j=i+1;j<=n;j++)
            {
                if(a[j]<a[t])
                {
                    t=j;
       //             minv=a[j];
     //               printf("change!\n");
                }

            }
        k=a[t];
        a[t]=a[i];
        a[i]=k;

        k=x[t];
        x[t]=x[i];
        x[i]=k;
   // printf("minv1=%d",minv);

    }

}
void pri()
{
    printf("a:\n");
    for(int i=1;i<=n;i++)
        printf(" %d ",a[i]);
    printf("\nx:\n");
    for(int i=1;i<=n;i++)
        printf(" %d ",x[i]);
    printf("\n");
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);

    scanf("%d",&n);
    a=(int *)malloc(sizeof(int )*(n+1));//记载数字
    x=(int *)malloc(sizeof(int )*(n+1));//记载数目

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
        x[i]=1;

    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]==a[j])
            {

                x[j]++;
   //             printf("i=%d,j=%d",i,j);
                for(int k=i;k<n;k++)
                {
                    a[k]=a[k+1];
                    x[k]=x[k+1];
                }
     //           pri();
                n--;
                i--;
                break;
            }

    Sort();


    for(int i=1;i<=n;i++)
        printf("%d %d\n",a[i],x[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
