//×½Å£

#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

#define cin fin
#define cout fout

ifstream fin("catchcow.in");
ofstream fout("catchcow.out");


int main(void)
{
	int N, K;
	int temp;
	int count[100010] = { 0 };   //¼Æ²½
	int visit[100010] = { 0 };   
	cin >> N;
	cin >> K;
	if (N <= K)
	{
		queue<int>q;
		q.push(N);
		while (!q.empty())
		{
			temp = q.front();
			visit[temp] = 1;
			q.pop();
			if (temp == K)
			{
				cout << count[temp] << endl;
				return 0;
			}
			else if (temp != K)
			{
				if ((temp - 1 >= 0) && (temp - 1 <= K) && visit[temp - 1] != 1)
				{
					q.push(temp - 1);
					visit[temp - 1] = 1;
					count[temp - 1] = count[temp] + 1;
				}
				if (((temp + 1) <= K) && (visit[temp + 1] != 1))
				{
					q.push(temp + 1);
					visit[temp + 1] = 1;
					count[temp + 1] = count[temp] + 1;
				}
				if ((temp < K )&&(visit[K * 2] != 1))
				{
					q.push(temp * 2);
					visit[temp * 2] = 1;
					count[temp * 2] = count[temp] + 1;
				}
			}
		}
	}
	else if (N >= K)
		cout << N - K << endl;
	return 0;
}
