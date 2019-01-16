#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int n,k;
queue<int> pos;
bool got[300000];


int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    scanf("%d%d",&n,&k);
    int i;
    pos.push(n);
    for (i=0;;i++)
    {
        int s=pos.size();
        for (int j=0;j<s;j++)
        {
            if (pos.front()==k)
                goto res;
            if (pos.front()>=0&&pos.front()<200000&&got[pos.front()]==false)
            {
                pos.push(pos.front()+1);
                pos.push(pos.front()-1);
                pos.push(pos.front()*2);
                got[pos.front()]=true;
            }
            pos.pop();
        }
    }
res:
    printf("%d",i);
}
