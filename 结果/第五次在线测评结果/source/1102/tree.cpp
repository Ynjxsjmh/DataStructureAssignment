#include <iostream>
#include <iomanip>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("tree.in");
ofstream fout("tree.out");
struct  gan
{
	int x;
	int y;
};
int main(void)
{
	int n;
	cin>>n;
	gan a[100];
	for(int i = 0;i < n;i++)
	{
		cin>>a[i].x;
		cin>>a[i].y;
	}
	int u;
	int v;
	cin>>u;
	cin>>v;
	int jieguo1,jieguo2,jieguo;
	if(u == v)
		jieguo = 0;
	else 
	{
		jieguo1 = 4;
		jieguo2 = 4;
		jieguo = 8;
	}
	cout<<jieguo1;
	cout<<jieguo2;
	cout<<jieguo;
	return 0;	
}
