#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int n;
struct numb
{
    int num;
    int count;
};

bool operator<(const numb& a,const numb &b)
{
    return a.num>b.num;
}
numb nb[51000];
int pos=0;
priority_queue<numb> nums;

int main()
{
    //freopen("/home/myhyh/in","r",stdin);
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        int j;
        for(j=0;j<pos;j++)
        {
            if(nb[j].num==tmp)
            {
                nb[j].count++;
                break;
            }
        }
        if(j==pos)
            nb[pos++]={tmp,1};
    }
    for(int i=0;i<pos;i++)
    {
        nums.push(nb[i]);
    }
    for(int i=0;i<pos;i++)
    {
        printf("%d %d\n",nums.top().num,nums.top().count);
        nums.pop();
    }
}
