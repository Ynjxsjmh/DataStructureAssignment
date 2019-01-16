#include<iostream>  
using namespace std;
#include<math.h>
#include<string.h>
#include<string>
#include<fstream>
struct circle
{
	int a;
	int b;
	int c;
}t[7000];

int w = 0;

	int main()
	{
		ifstream fin("circle.in");
		ofstream fout("circle.out");
		memset(t, -1, sizeof(t));
        int n = 0;
		fin >> n; int i; int j;
		for (i = 0; i<n; i++)
			fin >> t[i].a >> t[i].b >> t[i].c;
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (((t[i].a - t[j].a)*(t[i].a - t[j].a) + (t[i].b - t[j].b)*(t[i].b - t[j].b)) <= ((t[i].c + t[j].c)*(t[i].c + t[j].c)))
				{
					break;
				}
			}
			if (j == i)
			{
				w++;
			}

		}
		
		fout << w + 1 << endl;
		return 0;
	}