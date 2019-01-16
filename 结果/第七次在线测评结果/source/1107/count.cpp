#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int now=0;
class box
{
public:
    int math;
    int num;
};
bool Find(box*p,int x)
{
    int i;
    for(i=0;i<now;i++)
    {
        if(p[i].math==x)
        {
            p[i].num++;
            return true;
        }
    }
       p[now].math=x;
       p[now].num=1;
    now++;
    return true;
}
bool cmp(const box &a,const box&b)
{
    return a.math < b.math;
}
int main()
{
    freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    int n,j,x,i;
    scanf("%d",&n);
    box *p=new box[n];
    for(j=0;j<n;j++)
    {
          scanf("%d",&x);
          Find(p,x);
    }
    sort(p,p+now,cmp);
    for(i=0;i<now;i++)
    {
        printf("%d %d",p[i].math,p[i].num);
        printf("\n");
    }

    fclose(stdin);
 	fclose(stdout);
}



