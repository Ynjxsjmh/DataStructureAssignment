#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 2010000
struct node{
    int x;
    int length;
};
node q[maxn];
int n,k;
bool wat[maxn];
int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
	scanf("%d%d",&n,&k);
    int hd,tl;
	hd=0;
	tl=1;
	q[tl].x=n;q[tl].length=0;
	wat[n]=1;
	while(hd<tl){
	    hd++;
		node now=q[hd];
		if(now.x==k){
			printf("%d\n",now.length);
			return 0;
		}
		if(now.x<=k && !wat[now.x+1]){
			wat[now.x+1]=1;
			tl++;
			q[tl].x=now.x+1;
			q[tl].length=now.length+1;
		}
		if(now.x<=k && !wat[now.x*2]){
			wat[now.x*2]=1;
			tl++;
			q[tl].x=now.x*2;
			q[tl].length=now.length+1;
		}
		if(now.x-1>=0&&!wat[now.x-1]){
			wat[now.x-1]=1;
			tl++;
			q[tl].x=now.x-1;
			q[tl].length=now.length+1;
		}
	}
	return 0;
}
