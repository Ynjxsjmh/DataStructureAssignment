#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int  b[100005][8],cnt[10];

int main()
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int a[10];
    int n;
    while(~scanf("%d",&n))
    {
        memset(cnt, 0 , sizeof(cnt));
        for(int j=0; j<=n; j++)
        {
            if(j==0)
                for(int i=1;i<=7; i++) scanf("%d",&a[i]);
            else
                for(int i=1;i<=7; i++) scanf("%d",&b[j][i]);
        }
        sort(&a[1],&a[7]);

        //for(int i=1; i<=7; i++)
          //  cout<<a[i]<<' ';
        for(int j=1; j<=n; j++)
           sort(b[j]+1,b[j]+7);
      //  for(int j=1;j<=2;j++)
        //    for(int i=1; i<=7; i++)
          //  cout<<b[j][i]<<' ';
        int cn,i,j;
        for(int k=1; k<=n; k++)
        {
            cn=0;
            i=1; j=1;
            while(1)
            {
                if(i>7 || j>7)  break;
                if(a[i]<b[k][j]) { i++;continue;}
                if(a[i]>b[k][j])  { j++;continue;}
                if(a[i]==b[k][j]) { i++; j++; cn++;}
            }
            cnt[cn]++;
        }
        cout<<cnt[7]<<' '<<cnt[6]<<' '<<cnt[5]<<' '<<cnt[4]<<' '<<cnt[3]<<' '<<cnt[2]<<' '<<cnt[1]<<endl;
    }
    return 0;
}
