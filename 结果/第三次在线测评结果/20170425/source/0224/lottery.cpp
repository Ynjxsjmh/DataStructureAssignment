#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int n,aim[10],t[10];
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	
	scanf("%d",&n);
	for (int i = 0; i < 7; i ++) {
		scanf("%d",&aim[i]);
	}
	sort(aim, aim + 7);
	
	int i, j, sum;
	for (int k = 1; k <= n; k ++) {
		for (int i = 0; i < 7; i ++) {
			scanf("%d",&t[i]);
		}
		sort(t, t + 7);
		i = j = sum = 0;
		while (i < 7 && j < 7) {
			if (aim[i] == t[j]) {
				++ sum;
				++ i; ++ j;
			} else if (aim[i] > t[j]) {
				++ j;
			} else {
				++ i;
			}
		}
		++ cnt[sum];
	}
	
	printf("%d",cnt[7]);
	for (int i = 6; i >= 1; -- i) {
		printf(" %d",cnt[i]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
