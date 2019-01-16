/*
����   �� ��
�����ļ���һ��Ϊһ������n(1��n��100)����ʾ����������������������n-1�У�
��ʾ�ӽ��x�����y��Լ�������Ϊ1�������һ����������u��v����ʾ��ӽ��u�����v�ľ��롣
����    �� ��
��������ÿ����ռһ�У����α�ʾ��������������ȡ���ȼ����u�����v����롣
*/

#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

#define cin fin
#define cout fout

ifstream fin("tree.in");
ofstream fout("tree.out");


int main(void)
{
	int n;
	int x, y;  //��ǰ�����ֵ
	int u, v;   //Ҫ���Ҿ���ĵ�
	queue<int> q;
	int visit[100] = { 0 };
	int depth[100] = { 0 }; //��ʾÿ��������ȣ�Ȼ�������ֵ
	int max = 0;  //��ʾ��ȵ����ֵ
	int wide = 0;   //��ʾ���
	int widemax = 0;  //��ʾ�����
	cin >> n;    //��ʾ������������
	int root = 1;
	int length[100][2] = { 0 };
	int Len[100] = { 0 };
	int flag = 0;
	visit[root] = 1;
	depth[1] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		length[x][y] = 1;
		depth[y] = depth[x] + 1;
	}
	cin >> u >> v;
	for (int i = 1; i <= n; i++)
	{
		if (max < depth[i])
			max = depth[i];
	}
	for (int i = 1; i <= n; i++)
	{
		wide = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (depth[j] == depth[i])
				wide++;
		}
		if (widemax < wide)
			widemax = wide;
	}
	
	cout << max << endl; //��ʾ���
	cout << widemax << endl;    //��ʾ���
	q.push(u);
	for (int i = 0; i < n; i++)
	{
		if (length[i][u] == 1)   //��u��i
		{
			q.push(i);
			if (Len[i] == 0)
				Len[i] = Len[u] + 2;
			if (Len[i] != 0)
				if (Len[i] > Len[u] + 2)
					Len[i] = Len[u] + 2;
		}
		if (length[u][i] == 1)
		{
			q.push(i);
			if (Len[i] == 0)   //δ���ʹ�
				Len[i] = Len[u] + 1;
			if (Len[i] != 0)
				if (Len[i] > Len[u] + 1)
					Len[i] = Len[u] + 1;
		}
		q.pop();
	}cout << Len[v] << endl;




}