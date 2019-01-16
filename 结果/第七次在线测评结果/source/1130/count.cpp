#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 50005
struct A
{
   int num;
   int sum;
}cnt[maxn];
bool cmp(A a,A b)
{
    return a.num<b.num;
}
int main()
{
    int n,m;
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        cnt[i].num=m;
        cnt[i].sum=1;
    }
    sort(cnt,cnt+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(cnt[i].num==cnt[i+1].num)
        {
            cnt[i+1].sum+=cnt[i].sum;
            cnt[i].num=0;
        }
        if(cnt[i].num==0) continue;
        printf("%d %d\n",cnt[i].num,cnt[i].sum);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
