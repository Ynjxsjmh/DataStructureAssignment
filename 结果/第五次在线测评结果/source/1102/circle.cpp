#include <iostream>
#include <iomanip>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
struct cir
{
	int x;
	int y;
	int r;
};
int hanshu(cir a,cir b)
{
	int cot = 0;
	int p1;
	p1 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	int p2;
	p2 = a.r + b.r;//半径的和
		if(p1 > p2 * p2)
		{
			cot++;
		}
	return cot;
}
ifstream fin("circle.in");
ofstream fout("circle.out");
int main(void)
{
	int cit;
	int n;//输入圆的个数
	cin>>n;
	//cout<<endl;
	cir cir[10];
	for(int i = 0;i < n;i++)
	{
		cin>>cir[i].x;
		cin>>cir[i].y;
		cin>>cir[i].r;
	}
	if(n == 1)
	{
		cit = 1;
	}
	if(n == 2)
	{
		int p1;
		p1 = (cir[0].x - cir[1].x) * (cir[0].x - cir[1].x) + (cir[0].y - cir[1].y) * (cir[0].y - cir[1].y);
		int p2;
		p2 = cir[0].r + cir[1].r;//半径的和
		//int p3;
		/*if(cir[0]->r - cir[1]->r >= 0)
		{
			p3 = cir[0]->r - cir[1]->r;
		}
		else 
		{
			p3 = cir[1]->r - cir[0]->r;
		}*/
		/*if(p1 <= p2 * p2)
		{
			cit = 1;
			//cout<<"1"<<endl;
		}*/
		if(p1 > p2 * p2)
		{
			cit = 2;
		}
		else 
			cit = 1;
	}
	if(n > 2)
	{
		int f = 0;
		int p1;
		p1 = (cir[0].x - cir[1].x) * (cir[0].x - cir[0].x) + (cir[1].y - cir[1].y) * (cir[1].y - cir[1].y);
		int p2;
		p2 = cir[0].r + cir[1].r;//半径的和
		if(p1 > p2 * p2)
		{
			cit = 2;
		}
		else 
			cit = 1;
		int e = 0;
		for(int j = 2;j < n;j++)
		{
			for(int k = 0;k < j;k++)
			{
				e = hanshu(cir[j],cir[k]);
				if(e == 0) break;
				else
					f = f + e - 1;
			}
			cit = cit + f;
		}
	//	cit = cit + e;
	}
	cout<<cit;
	return 0;
}
