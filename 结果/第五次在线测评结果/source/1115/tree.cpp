#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("tree.in");
ofstream fout("tree.out");
#define cin fin
#define cout fout


class A
{
public:
	int num;
	int *p;
	A()
	{
		int a,b;
		cin >> num;
		p = new int[num+1];
		memset(p,0,sizeof(int)*(num+1));
		read();
		cin >> a >> b;
		cout << deep() << endl << width() << endl << dis(a,b) << endl;
	}
	void read()
	{
		int x,y;
		for(int i = 2 ; i <= num ; i++)
		{
			
			cin >> x >> y;
			p[y] = x;
		}
	}
	int find(int x)
	{
		int c = 0;
		while(p[x] != 0)
		{
			x = p[x];
			c++;
		}
		return c;
	}
	int deep()//深度
	{
		int d = 0,t;
		for(int i = 1 ; i <= num ; i++)
		{
			t = find(i);
			if(t > d)
			{
				d = t;
			}
		}
		return d;
	}
	int width()//宽度
	{
		int c = 0,k = 0,i,j;
		int *w = new int[num+1];
		memset(w,0,sizeof(int)*num+1);
		for(i = 1 ; i <= num ; i++)
		{
			w[i] = find(i);
		}//层次
		for(i = 1 ; i <= num ; i++)
		{
			for(j = 1 ; j <= num ; j++)
			{
				if(w[i] == w[j] && i != j)
					k++;
			}
			
			if(c < k)
				c = k;
			k = 0;
		}
		return c;
	}
	int dis(int x,int y)
	{
		int aa;
		int stepup = 0 , stepdown = 0;
		aa = find(x) - find(y);
		while(aa != 0)
		{
			if(aa > 0)
			{
				y = p[y];
				stepdown++;
				aa--;
			}
			else if(aa < 0)
			{
				x = p[x];
				stepup++;
				aa++;
			}
		}//同高度
		while(x == y)
		{
			x = p[x];
			y = p[y];
			stepup++;
			stepdown++;
		}
		return stepup*2+stepdown;
	}

};


int main()
{
	A a;

	return 0;
}