#include <fstream>
#include<queue>
#include<iostream>
using namespace std;

#define cin fin
#define cout fout

ifstream fin("catchcow.in");
ofstream fout("catchcow.out");
queue<int> q;
bool flag[10005];
int Find(int n,int k)
{
    int next,head;
    int m=0;
    if(n>=k) return n-k;
    else
    {
        head=n;
        q.push(head);
        flag[n]=true;
        while(!q.empty())
        {
            head=q.front();
            q.pop();
            for(int t=0;t<3;t++)
            {
                if(t==0) next=head+1;
                if(t==1) next=head-1;
                if(t==2) next=head*2;
            if(!flag[next])
            q.push(next);
            flag[next]=true;
            m++;
            }

        }
    }
}
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    cout<<Find(n,k);
}
