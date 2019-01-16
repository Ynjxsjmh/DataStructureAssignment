#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
	ifstream fin("lottery.in");
	ofstream fout("lottery.out");
	int num,i,j,k,t;
	short a[7] = {0},b[7];
	int p[8] = {0};
	fin >> num;
	fin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
	for(i = 0; i < num;i++)
	{
		t = 0;
		for(j = 0 ; j < 7 ; j++)
		{
			fin >> b[j];
		}
		for(j = 0;j<7;j++)
		{
			for(k = 0;k < 7;k++)
			{
				if(a[j] == b[k])
					t++;
			}
		}
		p[t]++;


	}



	for(i = 7; i > 0 ; i--)
	{
		fout << p[i] << ' ';
	}


	return 0;
}