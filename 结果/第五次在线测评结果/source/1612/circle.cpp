#include<stdio.h>
#include<math.h>
struct t_circle{
	int x, y, r;
	int vis;
}circle[7000];
int main()
{
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	int n, i, j, t = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d", &circle[i].x, &circle[i].y, &circle[i].r);
		circle[i].vis = i;	
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = 1; j < n; j++)
		{
			if(sqrt(pow((circle[i].x - circle[j].x), 2) + pow((circle[i].y - circle[j].y), 2)) < (circle[i].r + circle[j].r)) 
			{
				if(circle[j].vis == j)
					circle[j].vis = circle[i].vis;
				else
					circle[i].vis = circle[j].vis; 				
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		if(circle[i].vis == i)
			t++;
	}
	printf("%d", t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
