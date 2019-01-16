#include<stdio.h>
void Q_sort(int a[], int n)
{
	int i = 0;
	int j = n - 1;
	int key = a[0];//�ڿ�
	if(n > 1)
	{
		while(i != j)//��i��j����ȵ�ʱ����У�������򷵻���һ��
		{
			for(; i < j; j--)//�Ӻ�����һ�����ó������Ǹ�Ԫ��С�ģ������µ�Ԫ��ȥ���
			{
				if(a[j] < key){
					a[i] = a[j];
					break;
				}
			}
			for(; i < j; i++)//��ǰ����һ�����ó������Ǹ�Ԫ�ش�ģ������µ�Ԫ��ȥ���
			{
				if(a[i] > key){
					a[j] = a[i];
					break;
				}
			}
			a[i] = key;//�����ʣ�µĿ�����
		}
		Q_sort(a, i); //���ÿ���������key���
		Q_sort(a + i + 1, n - i - 1);//���ÿ���������key�Ҳ�
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
