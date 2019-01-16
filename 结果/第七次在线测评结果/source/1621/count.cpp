// count.cpp : 定义控制台应用程序的入口点。
//

#include"stdio.h"
#include"algorithm"
using namespace std;
int a[50010];

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	int x1, x2=0;
	int b1, b2,i;
	scanf("%d", &b1);
	for (i = 1; i <= b1; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + b1 + 1);
	x1 = a[1];
	i = 1;
	while (i <= b1)
	{
		while (a[i] == x1)
		{
			x2++;
			i++;
		}
		printf("%d %d\n", x1, x2);
		x2 = 0;
		x1 = a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	

}

