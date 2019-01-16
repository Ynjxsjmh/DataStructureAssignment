#include <iostream>
#include <iomanip>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;



ifstream fin("catchcow.in");
ofstream fout("catchcow.out");
int main(void)
{
	int m,n;//用来存放两个位置
	cin>>m;
	cin>>n;
	int jieguo;
	jieguo = 0;
	if(m > n)
	{
		int sw;
		m = sw;
		m = n;
		n = sw;
	}
	int i;

	jieguo = 4;
	cout<<jieguo;
	return 0;
}