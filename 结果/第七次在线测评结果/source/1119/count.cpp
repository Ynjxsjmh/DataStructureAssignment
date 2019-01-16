#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void qsort(int *a, int m, int n)
{
	if (m >= n)
	{
		return;
	}
	int i, j, k, r;
	i = m;
	j = n + 1;
	k = a[m];
	while (i<j)
	{
		i++;
		while (a[i]<k)
		{
			i++;
		}
		j--;
		while (a[j]>k)
		{
			j--;
		}
		if (i<j)
		{
			r = a[i];
			a[i] = a[j];
			a[j] = r;
		}
	}
	r = a[m];
	a[m] = a[j];
	a[j] = r;
	qsort(a, m, j);
	qsort(a, j + 1, n);
}

void sort(int* a, int m, int n)
{
	int i, j, k, r;
	for (i = m; i < n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			if (a[k] > a[j])
			{
				k = j;
			}
		}
		r = a[i];
		a[i] = a[k];
		a[k] = r;
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int a[60000], b[60000], n, i, j, pre;
	pre = -1;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = 2000000010;
	sort(a, 1, n);
	a[0] = -1;
	for (i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
		{
			pre++;
			b[pre]++;
		}
		else
		{
			b[pre]++;
		}
	}
	pre = -1;
	for (i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
		{
			pre++;
			cout << a[i] << " " << b[pre] << endl;
		}
	}
}
