#include <stdio.h>
#include <string.h>
#include <queue>
#define N 100001
using namespace std;

struct node
{
        int x,step;
};


int main()
{
        freopen("catchcow.in","r",stdin);
        freopen("catchcow.out","w",stdout);
        queue<node> Q;
        int map[N]={0},x,k;
        node n,next;
        scanf("%d%d",&x,&k);
        if(x<0||x>N-1)
                return 0;
        n.x=x;
        n.step=0;
        map[x]=1;
        Q.push(n);
        while(!Q.empty())
        {
                n=Q.front();
                Q.pop();
                if(n.x==k)
                {
                        printf("%d\n",n.step);
                        break;
                }
                next=n;
                next.x=n.x+1;
                if(!(next.x<0||next.x>=N||map[next.x]))
                {
                        next.step=n.step+1;
                        map[next.x]=1;
                        Q.push(next);
                }
                next.x=n.x-1;
                if(!(next.x<0||next.x>=N||map[next.x]))
                {
                        next.step=n.step+1;
                        map[next.x]=1;
                        Q.push(next);
                }
                next.x=n.x*2;
                if(!(next.x<0||next.x>=N||map[next.x]))
                {
                        next.step=n.step+1;
                        map[next.x]=1;
                        Q.push(next);
                }
        }
        return 0;
}
