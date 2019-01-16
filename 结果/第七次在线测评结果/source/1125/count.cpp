#include<iostream>
#include<fstream>
using namespace std;
ifstream in("count.in");
ofstream out("count.out");
int main()
{
	int allnum;
	long long int num,max_num= 20000000;
	long long int *temper = new long long int[max_num+2];
	in >> allnum;

	for (long long int i = 1; i <= max_num; i++)
	{
		temper[i] = 0;
	}

	for (int i = 1; i <= allnum; i++)
	{
		in >> num;
		temper[num]++;
	}

	for (long long int i = 1; i <= max_num; i++)
	{
		if (temper[i] != 0)
			out << i << " " << temper[i] << endl;
	}
}