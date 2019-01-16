#include<iostream>
#include<cstdio>

#define MAX_N 50000
#define LL long long
using namespace std;

LL array[MAX_N+5];

int Partition(LL *a, int i, int j)
{
    LL key = a[i];
    while(i < j)
    {
        while(i < j && key <= a[j]) j--;
        a[i] = a[j];
        while(i < j && key >= a[i]) i++;
        a[j] = a[i];
    }
    a[i] = key;
    return i;
}

void sort(LL *a, int left, int right)
{
    if(left >= right) return ;
    int i = Partition(a,left,right);
    sort(a, left, i - 1);
    sort(a, i + 1, right);

}

int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);

    int n,tmp,num=1;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    sort(array,0,n-1);

    tmp=array[0];
    for(int i=1;i<=n;i++)
    {
        if(tmp==array[i]) num++;
        else
        {
            printf("%d %d\n",tmp,num);
            tmp=array[i];
            num=1;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
