#include<stdio.h>
int compare(int r[7],int a[7])
{
    int i,j;
    int count=0;
    for(i=0;i<7;i++)
        for(j=0;j<7;j++)
        if(a[i]==r[j])
        count++;
    return count;
}

int main()
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int n;
    scanf("%d",&n);
    int r1[7];//中奖号码
    int i;
    for(i=0;i<7;i++)
        scanf("%d",&r1[i]);
    int r2[7];//结果
    for(i=0;i<7;i++)//结果的初始化
        r2[i]=0;
    int j,k;
    int a[7];
    int m;//中奖号码个数
    for(j=0;j<n;j++)
    {
        for(k=0;k<7;k++)
            scanf("%d",&a[k]);
        m=compare(r1,a);
        switch(m)
        {
            case 7:r2[0]++;break;
            case 6:r2[1]++;break;
            case 5:r2[2]++;break;
            case 4:r2[3]++;break;
            case 3:r2[4]++;break;
            case 2:r2[5]++;break;
            case 1:r2[6]++;break;
        }
    }
    for(i=0;i<7;i++)
        printf("%d ",r2[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;

}
