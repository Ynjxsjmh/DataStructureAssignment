#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 50;

int len;

char inorder[maxn];
char postorder[maxn];
char preorder[maxn];
int vis[maxn];

void preorder_ans(int i)
{
	if(!vis[i] && i >= 0 && i < len)
	{
		printf("%c",postorder[i]);
		vis[i] = 1;
		int cnt = 0;
		while(inorder[cnt] != postorder[i])
			cnt++;
		preorder_ans(cnt-1);
		preorder_ans(i-1);
	}
}

int main()
{
	freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
	memset(inorder,0,sizeof(inorder));
	memset(postorder,0,sizeof(postorder));
	memset(preorder,0,sizeof(preorder));
	memset(vis,0,sizeof(vis));
	scanf("%s %s",inorder,postorder);
	for(len = 0 ; postorder[len] ; len++);
	preorder_ans(len-1);
	return 0;
}
