#include <iostream>
#include <queue>
using namespace std;
int jiangRenShu[8]={0};
int jiangHao[34]={0};
int n;
int main()
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<7;i++)
    {
        scanf("%d",&tmp);
        jiangHao[tmp]++;
    }
    int count=0;
    for (int i=0;i<n;i++)
    {
        count=0;
        for(int j=0;j<7;j++)
        {
            scanf("%d",&tmp);
            if (jiangHao[tmp])
                count++;
        }
        jiangRenShu[count]++;
    }
    printf("%d %d %d %d %d %d %d",
           jiangRenShu[7],
            jiangRenShu[6]
            ,jiangRenShu[5],
            jiangRenShu[4],
            jiangRenShu[3],
            jiangRenShu[2],
            jiangRenShu[1]);
}
