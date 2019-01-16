#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

const int maxn = 100001;
int process[maxn];
bool visits[maxn];
queue<int> q;
int mybfs(int n, int k);
void solve();
int main()
{
    freopen("catchcow.in", "r", stdin);
    freopen("catchcow.out", "w", stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
void solve()
{
	int n, k;
    while(cin>>n>>k)
    {
    	memset(process, 0, sizeof(process));
		memset(visits, false, sizeof(visits));
	    while(!q.empty())
			q.pop();
	    if(n >= k)
	        printf("%d\n", n - k);
	    else
	        printf("%d\n", mybfs(n, k));
	}
}
int mybfs(int n, int k)
{
	int top, next;
	q.push(n);
	visits[n] = true;
	process[n] = 0;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		for(int i = 0; i < 3; i++)
		{
			if(i == 0)
				next = top - 1;
			if(i == 1)
				next = top + 1;
			if(i == 2)
				next = top * 2;
			if(next < 0 || next >= maxn)
				continue;
			if(!visits[next])
			{
				q.push(next);
				process[next] = process[top] + 1;
				visits[next] = true;
			}
			if(next == k)
				return process[next];
		}
	}
}
