#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin("circle.in");
ofstream fout("circle.out");

#define cin fin
#define cout fout

struct fam
{
int x;
int y;
int r;
int father;
fam()//初始化
{
	x = 0; y = 0;r = 0;
	father = -1;
}
};



class A
{
public:
	int num;
	fam *p;
	A()
	{
		cin >> num;
		p = new fam[num];
		creat();
	}
	void creat()
	{
		for(int i = 0 ; i < num ; i++)
		{
			cin >> p[i].x >> p[i].y >> p[i].r;
		}

	}
	bool is_fam(int a, int b)
	{
		double R,D;
		D = sqrt(1.0*((p[a].x-p[b].x)*(p[a].x-p[b].x) + (p[a].y+p[b].y)*(p[a].y+p[b].y)));
		R = p[a].r + p[b].r;
		if(D > R)
			return false;//两者不相邻
		else
			return true;//两者相邻

	}
	int findfather(int x)
	{
		while(p[x].father != -1)
		{
			x = p[x].father;
		}
		return x;
	}
	void un(int x,int y)
	{
		if(is_fam(x,y) == true)
		{
			p[y].father = findfather(x);
		}
	}

	int sum()
	{
		int c = 0;
		for(int i = 0 ; i < num ; i++)
		{
			if(p[i].father == -1)
				c++;
		}
		return c;
	}
	~A()
	{
		for(int i = 0 ; i < num-1 ; i++)
		{
			for(int j = i+1 ; j < num ; j++)
			{
				un(i,j);
			}
		}
		cout << sum() << endl;
		delete[] p;
	}
};


int main()
{
	
	A a;

	



	return 0;
}