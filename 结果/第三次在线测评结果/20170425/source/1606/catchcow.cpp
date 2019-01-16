#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define maxn 100005
//coder:mortal
using namespace std;
int q[maxn*10], step[maxn];
bool vis[maxn];
int n, k, nxt, head, tail;

int read()
{
	int x = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int bfs()
{
	head = 0, tail = 1; q[tail] = n;
	step[n]=0; vis[n]=1;
	while (head != tail)
	{
		head++; if (head == maxn) head = 1;
		int now = q[head];
		for(int i = 0; i < 3; i++)
		{
			if(i == 0) nxt = now - 1;
			else if(i == 1) nxt = now + 1;
			else nxt = now * 2;
			if((nxt > maxn) || (nxt < 0))  continue; 
			if(!vis[nxt])
			{
				tail++; if (tail == maxn) tail = 1;
				q[tail] = nxt;
				step[nxt] = step[now] + 1;
				vis[nxt] = 1;
			}
			if(nxt == k)  return step[nxt];
		}
	}
	return -1;
}

int main()
{
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	memset(vis, 0, sizeof(vis));
	n = read(); k = read();
	if(n >= k)
        printf("%d", n - k);
	else
		printf("%d", bfs());
	fclose(stdin);
	fclose(stdout);
	return 0;
}