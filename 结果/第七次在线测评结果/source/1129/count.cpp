#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>


using namespace std;

const int N=50005;

int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("count.in","r");
    fp2=fopen("count.out","w");
    int a[N];    //a数组来记录出现的元素
    int Count[N];        //Count数组来记录元素出现的次数
    int n;
    int b=0,c=0,sum=1;
    fscanf(fp1,"%d",&n);
    for(int i=0;i<n;i++)
        fscanf(fp1,"%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])sum++;
        else
        {
            Count[b++]=sum;sum=1;
        }
    }
    for(int i=0;i<b;i++)
    {
        c=c+Count[i];
        fprintf(fp2,"%d %d\n",a[c-1],Count[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
