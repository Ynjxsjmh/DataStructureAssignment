#include<stdio.h>
int main()
{
	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout); 
	int n, sum = 0, a[8], win[8], i, m = 0, x, is_win[8] = {0,0,0,0,0,0,0,0}, j;
	scanf("%d", &n);
	for(i = 0; i < 7; i++)
		scanf("%d", &win[i]);
	while(m < n)
	{
		for(i = 0; i < 7; i++)
			scanf("%d", &a[i]);
		for(i = 0; i < 7; i++)
		{
			for(j = 0; j < 7; j++)
			{
				if(a[j] == win[i])
				{
					sum++;
					break;
				}
			}
		}
		m++;
		is_win[sum - 1]++;
		sum = 0;
	}
	for(i = 6; i >= 0; i--)
		printf("%d ", is_win[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
