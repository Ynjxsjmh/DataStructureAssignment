#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int Maxn=200000;

int dis[Maxn+5];
queue<int> que;
bool inQue[Maxn+5];

inline void spfa(int src){
	memset(dis,-1,sizeof(dis));
	memset(inQue,false,sizeof(inQue));
	while(!que.empty()) que.pop();

	dis[src]=0;
	inQue[src]=true;
	que.push(src);

	while(!que.empty()){
		int now=que.front();que.pop();

		int mve=0;

		mve=now-1;
		if (0<=mve && mve<=Maxn){
			if (dis[mve]==-1 || dis[mve]>dis[now]+1){
				dis[mve]=dis[now]+1;
				if (!inQue[mve]){
					que.push(mve);
					inQue[mve]=true;
				}
			}
		}

		mve=now+1;
		if (0<=mve && mve<=Maxn){
			if (dis[mve]==-1 || dis[mve]>dis[now]+1){
				dis[mve]=dis[now]+1;
				if (!inQue[mve]){
					que.push(mve);
					inQue[mve]=true;
				}
			}
		}

		mve=now*2;
		if (0<=mve && mve<=Maxn){
			if (dis[mve]==-1 || dis[mve]>dis[now]+1){
				dis[mve]=dis[now]+1;
				if (!inQue[mve]){
					que.push(mve);
					inQue[mve]=true;
				}
			}
		}

		inQue[now]=false;
	}
}

int main(){
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);

	int src,sink;
	scanf("%d%d",&src,&sink);
	spfa(src);
	printf("%d\n",dis[sink]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
