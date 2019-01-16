#include<stdio.h>
#define Max 100005
int n;//FJ place
int k;//Cow Place
int a[Max];//step place
int i = 0 ;//step queue
int j = 0 ;//queue
int time[Max];//the time cost
void input()
{
	scanf("%d%d",&n,&k);
}
void in(int t)
{
	a[j] = t;
	j = (j+1)%Max;
}
void solve()
{
	if(time[a[i]+1] == 0 && a[i]+1<Max)
 	{
		time[a[i]+1] = time[a[i]]+1;
		in(a[i]+1);
	}
	if(time[a[i]-1] == 0 && a[i] - 1 >=0)
	{
		time[a[i]-1] = time[a[i]] + 1;
		in(a[i]-1);
	}
	if(time[a[i]*2] == 0 && a[i] * 2 < Max)
	{
		time[a[i]*2] = time[a[i]] + 1;
		in(a[i]*2);
	}
	i = (i+1)%Max;
 }

int main()
{
    	freopen ("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	input();
	if(n>=k) printf("%d", n - k);
	else
	{
		in(n);
		while(time[k] == 0) solve();
		printf("%d",time[k]);
	}
		fclose(stdin);
	fclose(stdout);
	return 0;
}
