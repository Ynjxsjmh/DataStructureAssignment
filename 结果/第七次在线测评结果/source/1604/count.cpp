#include<algorithm>
#include<stdio.h>
#include<string.h>
#define maxsize 50000
using namespace std;
int N;
long long num[maxsize+5];
void input()
{
	scanf("%d",&N);
	for(int i = 1; i <= N ; i ++)
		scanf("%ld",&num[i]);
}
void solve()
{
	int ans = 0;
	sort(num+1,num+N+1);
	for(int i = 1; i <= N ; i ++)
	{
		ans++;
		if(num[i+1]!=num[i])
		{
			printf("%ld %d\n",num[i],ans);
			ans = 0;
		}
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	input();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
