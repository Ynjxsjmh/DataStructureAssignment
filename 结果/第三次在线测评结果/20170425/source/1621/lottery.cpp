// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include"stdio.h"
int main() {
	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout);
	int x1, i;
	int j;
	int JL;
	int shu[8];
	int JS[8];
	int jiang[8];
	scanf("%d", &x1);
	for (i = 0; i<7; i++)
	{
		scanf("%d", &jiang[i]);
	}
	for (i = 0; i <= 7; i++)
		JS[i] = 0;
	while (x1--)
	{
		JL = 0;
		for (i = 0; i<7; i++)
			scanf("%d", &shu[i]);
		for (i = 0; i<7; i++)
			for (j = 0; j<7; j++)
			{
				if (shu[i] == jiang[j])
					JL++;
			}
		JS[7 - JL]++;
	}
	for (i = 0; i<7; i++)
		printf("%d ", JS[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;

}
