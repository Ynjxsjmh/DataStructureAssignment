#include <stdio.h>
#include <string.h>
using namespace std;
struct node
{
    int h=0;
    int par=0;
};

node nodes[300];
int maxh=0;
int maxw=0;
int widths[300];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    scanf("%d",&n);
    int posa,posb;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&posa,&posb);
        nodes[posb].h=nodes[posa].h+1;
        nodes[posb].par=posa;
        if(nodes[posb].h>maxh)
            maxh=nodes[posb].h;
    }
    scanf("%d%d",&posa,&posb);
    int len=0;
    if(nodes[posa].h>nodes[posb].h)
    {
        while(nodes[posa].h>nodes[posb].h)
        {
            posa=nodes[posa].par;
            len+=2;
        }
    }
    else
    {
        while(nodes[posb].h>nodes[posa].h)
        {
            posb=nodes[posb].par;
            len+=2;
        }
    }
    while(posa!=posb)
    {
        posa=nodes[posa].par;
        posb=nodes[posb].par;
        len+=3;
    }
    for(int i=1;i<=n;i++)
    {
        widths[nodes[i].h]++;
    }
    for(int i=0;i<=maxh+1;i++)
    {
        if(maxw<widths[i])
            maxw=widths[i];
    }
    printf("%d\n%d\n%d",maxh+1,maxw,len);
}
