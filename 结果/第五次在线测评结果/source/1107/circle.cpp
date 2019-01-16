#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
class node
{
    public:
    int x,y,r,loca;
    node(){loca=-1;}
};
bool li(node a, node b)
{
    int d=pow((pow((a.x-b.x),2)+pow((a.y-b.y),2)),0.5);
    if(d>(a.r+b.r))
        return true;
    else return false;
}
bool cmp(const  node &a,const node&b)
{
    return a.x < b.x;
}
node *p=new node[7000];
int Find(int i)
{
    if(p[i].loca==i)
        return i;
    return Find(p[i].loca);
}
void UNION(int j)
{
    p[j].loca=Find(j);
}
int main()
{
   //freopen("circle.in","r",stdin);
   //freopen("circle.out","w",stdout);
    int num;
    scanf("%d",&num);
    int i;
    for(i=0;i<num;i++)
    {
        scanf("%d",&p[i].x);
        scanf("%d",&p[i].y);
        scanf("%d",&p[i].r);
    }
    sort(p,p+num,cmp);
    int j;
    bool flag;
    p[0].loca=0;
    for(i=1;i<num;i++){
        flag=false;
    for(j=0;j<i;j++){
        if(!li(p[i],p[j]))
     {
         p[i].loca=j;
         flag=true;
     }
    }
        if(flag==false)
            p[i].loca=i;
    }
    for(i=0;i<num;i++)
        UNION(i);
    int n[num],id=0;
    for(i=0;i<num;i++)
    {
        n[p[i].loca]=1;
    }
    for(i=0;i<num;i++)
    {
        if(n[i]==1)
        id++;
    }
 printf("%d",id);
// fclose(stdin);
	//fclose(stdout);
}
