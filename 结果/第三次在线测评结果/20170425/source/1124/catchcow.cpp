#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int visit[100001];
int count[100001];
int main(){
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if(n>=k){
		printf("%d",n-k);
	}
	queue<int> a;
	a.push(n);
	visit[n]=1;
	int dangqian=n;
	int j=dangqian;
	while(!a.empty()){
		dangqian=a.front();
		
		a.pop();
		for(int i=0;i<3;i++){
			if(i==0) dangqian=j-1;
			else if(i==1) dangqian=j+1;
			else if(i==2) dangqian=j*2;
		}
		if(visit[dangqian]==0){
			visit[dangqian]=1;count[dangqian]=count[j]+1;
			a.push(dangqian);
			
		}
		if(dangqian==k){
			printf("%d",count[dangqian]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
