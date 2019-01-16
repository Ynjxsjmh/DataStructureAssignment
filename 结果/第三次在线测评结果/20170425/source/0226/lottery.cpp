#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int M = 1e+6+123;
int vis[M];
int s[8];
int main(){
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=7;i++){
		int t;
		cin>>t;
		vis[t]=1;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=7;j++){
			int t;
			cin>>t;
			ans+=vis[t];	
		}
		s[ans]++;
	}
	printf("%d",s[7]);
	for(int i=6;i>=1;i--)
		printf(" %d",s[i]);
		printf("\n");
	return 0;
}
