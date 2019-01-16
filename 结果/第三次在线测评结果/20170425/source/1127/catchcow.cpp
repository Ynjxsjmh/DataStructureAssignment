#include <iostream>
#include <fstream>
#include <queue>
#include <memory.h>
#define MAX 110000
using namespace std;
queue<int> q;
long long int n,k;
int step[MAX];
bool visit[MAX];
int bfs()
{  int next, head;
    q.push(n);
    step[n]=0;
    visit[n]=1;
    while(!q.empty())
    {
        head=q.front();
        q.pop();
        for(int i=0; i<3 ;i++)
        {
            if(i==0) next=head-1;
            else if(i==1) next=head+1;
            else  next=head*2;
            if(next>MAX || next<0 )  continue;
            if(!visit[next])
            {
              q.push(next);
              step[next]=step[head]+1;
              visit[next]=1;
            }
            if(next==k)  return step[next];
        }
    }
    return -1;
}
int main()
{   ifstream fin("catchcow.in");
    ofstream fout("catchcow.out");
    memset(visit,0,sizeof(visit));
    fin>>n>>k;
    if(n>=k)
    {
       fout<<n-k;
    }
    else
    {
       fout<<bfs();
    }

    return 0;
}


