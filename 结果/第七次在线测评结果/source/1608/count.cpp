#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn=5e4;

int n;
int num[Maxn+5];
int cnt,now;

inline bool cmp(int a,int b){return a<b;}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);

	//Input
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&num[i]);
	//Solve
	sort(num+1,num+n+1,cmp);
	
	//Output
	for (int i=1;i<=n;i++){
		if (i==1 || now!=num[i]) {
			if (i!=1) printf("%d %d\n",now,cnt);
			now=num[i];
			cnt=0;
		}cnt++;
	}
	if (cnt>0) printf("%d %d\n",now,cnt);

	fclose(stdin);
	fclose(stdout);
	return 0;
}