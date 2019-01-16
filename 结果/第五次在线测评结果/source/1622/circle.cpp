#include<stdio.h>
#include<math.h>
struct no
{
    int x;
    int  y;
    int r;
    int a[7000];
    int  num;
    int visited;

} node[7000] ;
int di(int i,int ri)
{
    int j;
    node[i].visited=ri;
     for(j=0;j<node[i].num;j++)
     {
         if(node[node[i].a[j]].visited==-1)
             di(node[i].a[j],ri);
     }
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n;int ring=0;
    int i,j;
    scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         node[i].visited=-1;
     }
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].r);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j&&(pow((node[i].x-node[j].x),2)+pow((node[i].y-node[j].y),2)<=pow((node[i].r+node[j].r),2)))
            {
                node[i].a[node[i].num]=j;
                node[i].num++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if( node[i].visited==-1)
        {
            ring++;
            node[i].visited=ring;
            di(i,ring);
        }
    }
    printf("%d",ring);
    return 1;
}
