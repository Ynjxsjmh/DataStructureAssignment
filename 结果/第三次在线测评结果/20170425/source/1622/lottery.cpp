#include<stdio.h>
long long n,i,j,a[7],b[7],c[7],time=0;
int main()
{
 freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<7;i++)
    {
        scanf("%d",&a[i]);
    }
    while(n>0)
    {
        for(i=0;i<7;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0;i<7;i++)
        {
           for(j=0;j<7;j++)
           {
               if(b[i]==a[j]){
                  time++;
                  break;
               }

           }
        }
        switch(time)
        {
            case 1:c[6]++;break;
            case 2:c[5]++;break;
            case 3:c[4]++;break;
            case 4:c[3]++;break;
            case 5:c[2]++;break;
            case 6:c[1]++;break;
            case 7:c[0]++;
        }
        n--;
        time=0;
    }
    printf("%d ",c[0]);
     for(i=1;i<7;i++)
    {
        printf("%d ",c[i]);
    }

return(0);

}
