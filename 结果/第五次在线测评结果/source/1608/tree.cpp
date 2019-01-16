#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn=1000;

struct Edge{
	int v,nxt;
	Edge(){}
	Edge(int v0,int n0){
		v=v0;
		nxt=n0;
	}
};
Edge e[Maxn*2+5];
int head[Maxn+5];
int nume;

inline void addEdge(int u,int v){
	e[++nume]=Edge(v,head[u]);
	head[u]=nume;
	e[++nume]=Edge(u,head[v]);
	head[v]=nume;
}

int n;
int dep[Maxn+5];
int cnt[Maxn+5];
int fa[Maxn+5];
bool vis[Maxn+5];

void dfs(int x,int from,int depth){
	fa[x]=from;
	dep[x]=depth;
	cnt[dep[x]]++;
	for (int i=head[x];i;i=e[i].nxt){
		int v=e[i].v;
		if (v!=from) dfs(v,x,depth+1);
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

	//Init
	memset(dep,0,sizeof(dep));
	memset(cnt,0,sizeof(cnt));
	memset(vis,false,sizeof(vis));
	//Input
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
	}
	//Solve
	int ansDep=0,ansCnt=0,ansLen=0;
	dfs(1,0,1);
	for (int i=1;i<=n;i++) ansDep=max(ansDep,dep[i]);
	for (int i=1;i<=ansDep;i++) ansCnt=max(ansCnt,cnt[i]);
	int u,v,lca=0;
	scanf("%d%d",&u,&v);
	for (int now=u;now;now=fa[now]) vis[now]=true;
	for (int now=v;!lca;now=fa[now]) if (vis[now]) lca=now;
	ansLen=(dep[u]-dep[lca])*2+(dep[v]-dep[lca]);
	//Output
	printf("%d\n%d\n%d\n",ansDep,ansCnt,ansLen);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}