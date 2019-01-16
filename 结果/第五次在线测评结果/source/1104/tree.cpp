/*
【输   入 】
输入文件第一行为一个整数n(1≤n≤100)，表示二叉树结点个数。接下来的n-1行，
表示从结点x到结点y（约定根结点为1），最后一行两个整数u、v，表示求从结点u到结点v的距离。
【输    出 】
三个数，每个数占一行，依次表示给定二叉树的深度、宽度及结点u到结点v间距离。
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
	int x, y;  //当前输入的值
	int u, v;   //要查找距离的点
	queue<int> q;
	int visit[100] = { 0 };
	int depth[100] = { 0 }; //表示每个数的深度，然后求最大值
	int max = 0;  //表示深度的最大值
	int wide = 0;   //表示宽度
	int widemax = 0;  //表示最大宽度
	cin >> n;    //表示二叉树结点个数
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
	
	cout << max << endl; //表示深度
	cout << widemax << endl;    //表示宽度
	q.push(u);
	for (int i = 0; i < n; i++)
	{
		if (length[i][u] == 1)   //从u到i
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
			if (Len[i] == 0)   //未访问过
				Len[i] = Len[u] + 1;
			if (Len[i] != 0)
				if (Len[i] > Len[u] + 1)
					Len[i] = Len[u] + 1;
		}
		q.pop();
	}cout << Len[v] << endl;




}