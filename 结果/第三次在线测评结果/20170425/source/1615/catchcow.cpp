#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;
int vis[100010];

int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    int s,e;
    while(~scanf("%d%d",&s,&e))
    {
        while(!q.empty())
            q.pop();
        memset(vis, 0, sizeof(vis));
        q.push(s);
        while(1)
        {
          //  cout<<"1"<<endl;
            if(q.front()== e)  break;
            if( vis[q.front()+1]==0 && q.front()+1>=0 && q.front()+1<=100000)
            {  q.push(q.front()+1); vis[q.front()+1] = vis[q.front()] +1;}
            if(vis[q.front()-1]==0  && q.front()-1>=0 && q.front()-1<=100000 )
            {  q.push(q.front()-1); vis[q.front()-1] = vis[q.front()] +1;}
            if(vis[q.front()*2]==0 && q.front()*2>=0 && q.front()*2<=100000)
            {  q.push(q.front()*2); vis[q.front()*2] = vis[q.front()] +1;}
            q.pop();
        }
       // cout<<"2"<<endl;
        printf("%d\n",vis[q.front()]);
    }
    return 0;
}
