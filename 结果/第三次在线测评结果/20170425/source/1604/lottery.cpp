#include<stdio.h>
#include<string.h>
int price[7];//�񽱺��� 
int level[7];//�����ȼ�
int myprice[7];
int n;//��Ʊ��Ŀ 
void input()
{
	scanf("%d",&n); 
	for(int i = 0 ; i < 7 ; i ++)
		scanf("%d",&price[i]);
}
void solve()
{
	int times = 0;
	int mylevel = 0;
	while(times < n)
	{
		times++;
		mylevel = 0;
		for(int i = 0 ; i < 7 ; i ++)
			scanf("%d",&myprice[i]);
		for(int i = 0 ; i < 7 ; i ++)
			for(int j = 0 ; j < 7 ; j ++)
			{
				if(price[i] == myprice[j])
					mylevel++;						
			}
		level[7-mylevel]++;
	}
}
void output()
{
	for(int i = 0 ; i < 7 ; i ++)
		printf("%d ",level[i]);
}
int main()
{
	freopen ("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	input();
	solve();
	output();
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
