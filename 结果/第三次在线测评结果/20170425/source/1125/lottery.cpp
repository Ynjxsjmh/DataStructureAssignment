//=====================================
//lottery
//=====================================
#include<iostream>
#include<fstream>
using namespace std;
//=====================================
int main() {
	ifstream in("lottery.in");
	ofstream out("lottery.out");
	int n, win[8], buyer[8],ans[8];
	memset(ans, 0, sizeof(ans));
	in >> n;                  //��������
	for (int i = 1; i <= 7; i++)
		in >> win[i];
	for (int j = 1; j <= n; j++) 
	{
		int temp = 0;
		for (int i = 1; i <= 7; i++)
		{
			in >> buyer[i];
			for (int k = 1; k <= 7; k++)
			{
				if (win[k] == buyer[i])
				{
					temp++;
					break;
				}
			}
		}
		ans[temp]++;
	}
	for (int i = 7; i >= 1; i--)
		out << ans[i]<<" ";
}