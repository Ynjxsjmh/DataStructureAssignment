#include <cstdio>
#include <cstring>

using namespace std;

int n;
int lty[10];
int ans[10];
int num[10];
int cNum[35];


int main(){
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=7;i++) scanf("%d",&lty[i]);

	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=7;j++) scanf("%d",&num[j]);
		for (int j=1;j<=7;j++) cNum[num[j]]++;
		for (int j=1;j<=7;j++) cnt+=cNum[lty[j]];
		for (int j=1;j<=7;j++) cNum[num[j]]--;
		ans[cnt]++;
	}

	for (int i=7;i>1;i--) printf("%d ",ans[i]);
	printf("%d\n",ans[1]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}