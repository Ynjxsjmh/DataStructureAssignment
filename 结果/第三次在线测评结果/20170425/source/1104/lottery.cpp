//Walmart彩票
#include<iostream>
#include<fstream>
using namespace std;


#define cin fin
#define cout fout


ifstream fin("lottery.in");
ofstream fout("lottery.out");

int main(void)
{
	int n;   //表示数目
	int i, j, k;
	int a[7];     //中奖号码
	int x;     
	int count;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0;  //各种奖项中奖张数
	cin >> n;
	for (i = 0; i < 7; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)   //依次检测每一行的号码
	{
		count = 0;
		for (j = 0; j < 7; j++)
		{
			cin >> x;
			for (k = 0; k < 7; k++)
			{
				if (a[k] == x)
				{
					count++;
					break;
				}
			}
		}
		switch (count)
			{
			case 1:c7++; break;
			case 2:c6++; break;
			case 3:c5++; break;
			case 4:c4++; break;
			case 5:c3++; break;
			case 6:c2++; break;
			case 7:c1++; break;
			default:break;
			}
	}
	cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << ' ' << c5 << ' ' << c6 << ' ' << c7 << endl;
	return 0;
}


