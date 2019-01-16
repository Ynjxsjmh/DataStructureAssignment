#include<stdio.h>
int main()
{
        freopen("lottery.in","r",stdin);
        freopen("lottery.out","w",stdout);
        int match=0,a[7]={0},buy[7]={0},win[7]={0};
        int n;
        scanf("%d",&n);
        for(int i=0;i<7;i++)
        {
                scanf("%d",&a[i]);
        }
        for(int k=0;k<n;k++)
        {
                match=0;
                for(int i=0;i<7;i++)
                {
                        scanf("%d",&buy[i]);
                }
                for(int i=0;i<7;i++)
                {
                        for(int j=0;j<7;j++)
                        {
                                if(a[i]==buy[j])
                                {
                                        match++;
                                        //break;
                                }
                        }
                }
                if(match!=0)
                        win[7-match]++;
        }
        for(int i=0;i<7;i++)
        {
                printf("%d ",win[i]);
        }
}
