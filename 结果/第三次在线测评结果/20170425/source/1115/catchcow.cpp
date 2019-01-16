#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("catchcow.in");
	ofstream fout("catchcow.out");
	int n , k,t = 0,i;
	fin >> n >> k;
	int a[30000] = {0};
	
	for(i = 0;i < 30000;i++)
	{
		if(i > 2)
		{
			a[i] = a[i/3];
			if(i%3 == 1)
				(a[i])++;
			else if(i%3 == 2)
				(a[i])--;
			else if(i%3 == 0)
				a[i]*=2;
		}
		else if(i == 0)
			a[i] = n+1;
		else if(i == 1)
			a[i] = n-1;
		else if(i == 2)
			a[i] = n*2;


		if(a[i] == k)
			break;
	}
	//cout << a[i] << endl;
	//cout <<i << endl;
	while(i != 0)
	{
		i = i/3;
		t++;
	}
	//for(i = 0;i < 150;i++)
	//	cout << a[i] << ' ';
	//cout << t;
	fout << t;
	return 0;
}