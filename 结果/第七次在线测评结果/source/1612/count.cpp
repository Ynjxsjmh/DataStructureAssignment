#include<stdio.h>
void Q_sort(int a[], int n)
{
	int i = 0;
	int j = n - 1;
	int key = a[0];//挖坑
	if(n > 1)
	{
		while(i != j)//当i与j不想等的时候进行，若相等则返回上一层
		{
			for(; i < j; j--)//从后面找一个比拿出来的那个元素小的，并用新的元素去填坑
			{
				if(a[j] < key){
					a[i] = a[j];
					break;
				}
			}
			for(; i < j; i++)//从前面找一个比拿出来的那个元素大的，并用新的元素去填坑
			{
				if(a[i] > key){
					a[j] = a[i];
					break;
				}
			}
			a[i] = key;//把最后剩下的坑填上
		}
		Q_sort(a, i); //利用快速排序排key左侧
		Q_sort(a + i + 1, n - i - 1);//利用快速排序排key右侧
	}
}
int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	int i, n, ans = 0;
	int a[50001], t;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Q_sort(a, n);
	t = a[0];
	for(i = 0; i < n; i++)
	{
		if(a[i] == t)
			ans++;
		else
		{
			printf("%d %d\n", t, ans);
			t = a[i];
			ans = 1;
		}
	}
	printf("%d %d", t, ans);
	return 0;
    fclose(stdin);
	fclose(stdout);
}
