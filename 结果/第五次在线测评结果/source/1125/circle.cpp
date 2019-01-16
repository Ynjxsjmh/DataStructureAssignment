// 第五次实验课
//              王瀚橙
//  ------圆的划分

#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
ifstream in("circle.in");
ofstream out("circle.out");
//==============================
long double howfar(long int a1, long int a2,long int b1,long int b2 )
{
	return sqrt(((a1-b1)*(a1-b1))+((a2-b2)*(a2-b2)));
}
int main()
{
	int all,ans=1;
	bool flag;
	long int p[8000][3];
	in >> all;
	if (all == 0) out<<0;
	for (int i = 1; i <= all; i++)   //dangqiandeshi  i
	{
		flag = true;
		int k=1;
		for (int j = 0; j < 3; j++)   
			in >> p[i][j];
		for (k = i-1; k >= 1; k--)  //congdi i-1 gentabi
		{
			if ((p[i][2] + p[k][2])-howfar(p[i][0], p[i][1], p[k][0], p[k][1]) <0.00001 )  //找到了
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans++;
		}
	}
	out<< ans-1;
}