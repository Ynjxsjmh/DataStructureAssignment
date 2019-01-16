#include<stdio.h>
#include<math.h>
#define maxsize 7000
int n;//圆的数量 
struct circle{
	int x, y;
	int r;	
}circles[maxsize+5];//圆 
int fa[maxsize+5]; //并查集
int fx[maxsize+5]; 
int find(int x)//并查集求根 
{
    if(fa[x]==x)      return x;
    if(fa[x] !=x)      
	fa[x]=find(fa[x]); 
    return fa[x];
}
void un(int x,int y)//合并 
{
	int fx,fy;
	fx=find(x);fy=find(y);
	if(fx!=fy)
	      fa[fy]=fx;
}
void input()
{
	int flag = 0;
	circle p;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d%d%d",&circles[i].x,&circles[i].y,&circles[i].r);
	}
}
int judge(int a,int b)
//判断两个圆是否属于同一块，是则返回1 
{
	int s1 = (circles[a].x-circles[b].x)*(circles[a].x-circles[b].x);
	int s2 = (circles[a].y-circles[b].y)*(circles[a].y-circles[b].y);
	if(sqrt(s1+s2) > circles[a].r+circles[b].r)	
		return 0;
	else 
		return 1;
}
void solve()
{
	for(int i = 1 ; i <= n ; i ++)
		fa[i] = i;//并查集初始化 
	for(int i = 1 ; i <= n - 1 ; i ++)//n个圆
	 	for(int j = i; j <= n ; j ++)
		{ 
		 	if(judge(i,j) == 1)
		 	{
		 		un(i,j);
			}
		} 

}
void output()
{
	int answer = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(fa[i]==i) answer++;
	printf("%d",answer);
}
int main()
{
	freopen ("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	input();
	solve();
	output();
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
