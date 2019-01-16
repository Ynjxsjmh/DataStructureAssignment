#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	int lin[n][n];
	int deep[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			lin[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		deep[i]=1;
	}
	for(int i=1;i<=n-1;i++){
		int m,p;
		scanf("%d%d",&m,&p);
		lin[m][p]=1;
		lin[p][m]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(lin[i][j]==1){        //if(lin[i][j]==1&&deep[j]==1) 
				deep[j]=deep[i]+1;
			}
		}
	}
	int a=0;
	for(int i=0;i<n;i++){
		if(deep[i]>a)
		a=deep[i];
	}
	printf("%d\n",a);
	int jisu[n+1];
	for(int i=0;i<n+1;i++){
		jisu[i]=0;
	}
	for(int i=0;i<n;i++){
		a=deep[i];
		jisu[a]++;
	}
	int ma=0;
	for(int i=0;i<n+1;i++){
		if(jisu[i]>ma)
		ma=jisu[i];
	}
	printf("%d\n",ma);
	int u,v;
	scanf("%d%d",&u,&v);
	printf("%d",((deep[u]-1)*2+deep[v]-1));
	
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
