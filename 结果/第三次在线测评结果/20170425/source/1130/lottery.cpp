#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("lottery.in","r");
    fp2=fopen("lottery.out","w");
    int n,m,a[34],b[7],c[7];
    memset(a,0,sizeof(a));
    fscanf(fp1,"%d",&n);
    for(int i=0;i<7;i++)
    {
        fscanf(fp1,"%d",&m);
        a[m]=1;
    }
    memset(c,0,sizeof(c));
    while(n--)
    {
        int sum=0;
        for(int i=0;i<7;i++)
            fscanf(fp1,"%d",&b[i]);
        for(int j=0;j<7;j++)
            if(b[j]<34)
                if(a[b[j]]==1)
                    sum++;
        c[sum-1]++;
    }
    for(int i=6;i>0;i--)
       fprintf(fp2,"%d ",c[i]);
    fprintf(fp2,"%d",c[0]);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
