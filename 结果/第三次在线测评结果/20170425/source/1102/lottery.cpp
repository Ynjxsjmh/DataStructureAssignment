#include <iostream>
#include <iomanip>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;




ifstream fin("lottery.in");
ofstream fout("lottery.out");
int main(void)
{
	int n;//������������������Ĳ�Ʊ����
	cin>>n;
	int z[7];
	for(int k = 0;k < 7;k++)//�����н���Ʊ������
		cin>>z[k];
	int a[7][1000];//�����Ʊ�ϵ�����
	for(int i = 0;i < 7;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cin>>a[i][j];
		}
	}
	int s[7];//��Ÿ��ཱ����Ŀ
	for(int m = 0;m < 7;m++)
	{
		s[m] = 0;
	}
	int p;
	p = 0;
	int count;
	while(p != n)
	{
		count = 0;
		for(int t = 0;t < 7;t++)
		{
			for(int y = 0;y < 7;y++)
				if(a[t][p] == z[y])
					count++;
		}
		int h;
		h = 7- count;
		s[h] = s[h]+1;
		p++;
	}
	for(int w = 0;w < 7;w++)
	{
		cout<<s[w];
		cout<<" ";
	}
	return 0;
}