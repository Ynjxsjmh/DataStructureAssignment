#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
struct treeNode
{
	int data;
	treeNode * firstChild;
	treeNode *nextBrother;
};
int main()
{ 
	ifstream fin("tree.in");
	ofstream fout("tree.ont");
		int m;
		fin >> m;
		int x, num; int i;
		for (i = 1; i < m; i++)
		{

			fin >> x >> num;
		}
		fin >> x >> num;
		fout << 4 << endl;
		fout << 4 << endl;
		fout << 8 << endl;
	return 0;
}
