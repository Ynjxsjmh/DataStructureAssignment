#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
struct tnode{
	int data;
	int deep;
	int father;
	int lchild, rchild;
}tnodes[maxsize+5];
int n;//结点个数 
int a,b;
int max;
int mmm;
void input()//根据输入数据建树 
{
	//struct tnode * p1, * p2;
	int x,y;
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	tnodes[x].data = x;
	tnodes[x].deep = 1;
	tnodes[y].data = y;
	tnodes[y].deep = 2;
	tnodes[x].lchild = y;
	tnodes[y].father = x;
	for(int i = 1 ; i < n - 1 ; i ++)
	{
		scanf("%d%d",&x,&y);
		tnodes[x].data = x;
		tnodes[y].data = y;
		tnodes[y].deep = tnodes[x].deep+1;
		if(tnodes[x].lchild == 0)
		{	
			tnodes[x].lchild = y;	
		}
		else if(tnodes[x].rchild == 0)
			tnodes[x].rchild = y;
		tnodes[y].father = x;
	}
}
/*void check(int a)
{
	if(tnodes[a].data!=0)
	{
		printf("%d",tnodes[a].data);
		check(tnodes[a].lchild);
		check(tnodes[a].rchild);
	}
 } */
int cost()
{
	int wid;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(tnodes[i].deep>max)
		max = tnodes[i].deep;
	}
	//printf("%d\n",max);
	
	for(int i = 1 ; i <= n ; i ++)
	{
		wid = 0;
		for(int j = 1 ; j <= n ; j ++)
		{
			if(tnodes[j].deep == i)
			wid++;
		}
		if(wid>mmm) mmm = wid; 
	}
//	printf("%d\n",mmm);
	
}
bool vis[maxsize+5];
int st(int x,int val)
{
	vis[x] = 1;
	if(x==b)
	{
		printf("%d",val);
		return 1;
	}
	if(tnodes[x].lchild!=0&&vis[tnodes[x].lchild] == 0)
	{
		if(st(tnodes[x].lchild,val+1) == 1) return 1;
	}
	if(tnodes[x].rchild!=0&&vis[tnodes[x].rchild] == 0)
	{
		if(st(tnodes[x].rchild,val+1) == 1) return 1;
	}
	if(tnodes[x].father!=0&&vis[tnodes[x].father ] == 0)
	{
		if(st(tnodes[x].father,val+2) == 1) return 1;
	}
	return 0;
}
int main()
{
	//freopen("tree.in",)
	freopen ("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	input();
	cost();
	scanf("%d%d",&a,&b);
	printf("%d\n%d\n",max,mmm);
	st(a,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
