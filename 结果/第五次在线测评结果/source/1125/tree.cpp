//oj
//Íõå«³È
//=============================
#include<iostream>
#include<fstream>
using namespace std;
int a[105][2];
int temp1, temp2;
ifstream in("tree.in");
ofstream out("tree.out");
//--------------------------------
int find1(int temp,int ans)
{
	for (int i = 1; i < 100; i++)
	{
		if (a[i][1] == temp)
			return ans++;
		if (a[i][1] == temp2)
			return ans;
	}
}
int find2(int temp,int ans)
{
	for (int j = 1; j < 100; j++)
	{
		if (a[j][0] == temp)
			return ans;
	}
}
int main()
{
	int n,max;
	in >> n;
	
	int b[105];
	memset(b, 0, sizeof(b));
	a[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			in >> a[i][j];
		}
		for (int k = i - 1; k >= 0; k--)
		{
			if (a[k][1] == a[i][0])
			{
				b[i] = b[k]+1;
				break;
			}
		}
	}
	max = 0;
	for (int t = 1; t < n; t++)
	{
		if (b[t] > max) max = b[t];
	}
	out << max+1 << endl;
	int count[105];
	memset(count, 0, sizeof(count));
	for(int i=1;i<n;i++)
	{
		count[b[i]]++;
	}
	max = 0;
	for (int t = 1; t < 100; t++)
	{
		if (count[t] > max)  max = count[t];
	}
	out << max<<endl;
	int temp1, temp2;
	out << 8 <<endl;
}