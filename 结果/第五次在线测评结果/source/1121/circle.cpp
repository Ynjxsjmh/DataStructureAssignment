# include<iostream>
# include<iomanip>
# include<cstdio>
# include<queue>
using namespace std;
struct circle
{
    int x;
    int y;
    int r;
    int m;
};
int main(void)
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    struct circle a[7000];

    int n,j,i,s=0,k,f;
    queue<int> t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
        cin>>a[i].r;
        a[i].m=0;
    }
    for(k=0;k<n;k++)
    {
        if(a[k].m==1)
            continue;
        t.push(k);
        a[k].m=1;
        while(!t.empty())
        {
        f=t.front();
          t.pop();
          for(i=0;i<n;i++)
           {
                  if(((a[i].x-a[k].x)*(a[i].x-a[k].x)+(a[i].y-a[k].y)*(a[i].y-a[k].y))<=(a[i].r+a[k].r)*(a[i].r+a[k].r))
                  {
                     if(a[i].m==0)
                     {
                         t.push(i);
                         a[i].m=1;
                      }

                   }
             }
         }
         s++;
    }
    cout<<s<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
