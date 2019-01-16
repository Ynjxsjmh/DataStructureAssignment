// catch the cow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
#include"queue"
using namespace std;

int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
	queue <int> q;
	int pre[10005];
	int cishu[10005];
	int start, en;
	int time = 0, tail,i;

	int x1,x2, x3, x4;
	for (i = 0; i <= 10004; i++)
	{
		pre[i] = 0; cishu[i] = 0;
	}
	scanf("%d %d", &start, &en);
	q.push(start);
	x1 = q.front();
	while (1)
	{
		x2 = x1 + 1;
		x3 = x1 - 1;
		x4 = 2 * x1;
		if (!cishu[x2])
		{
			q.push(x2);
			pre[x2] = x1;
			cishu[x2] = 1;
		}
		if (!cishu[x3])
		{
			q.push(x3);
			pre[x3] = x1;
			cishu[x3] = 1;
		}
		if (!cishu[x4])
		{
			q.push(x4);
			pre[x4] = x1;
			cishu[x4] = 1;
		}
		x1 = q.front(); q.pop();
		if (x2 == en || x3 == en || x4 == en)
			break;
	}
	if (x2 == en)
		tail = x2;
	else
	{
		if (x3 == en)
			tail = x3;
		else
			tail == x4;
	}
	while (pre[tail] != start)
	{
		tail = pre[tail];
		time++;
	}
	time++; printf("%d", time);
	fclose(stdin);
	fclose(stdout);

    return 0;
}

