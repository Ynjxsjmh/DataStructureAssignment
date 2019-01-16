#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ifstream in("preorder.in");
ofstream out("preorder.out");

int findleft(char*zhonggen,char temp)          //根据temp找左儿子
{
	for (int i = 0; i < strlen(zhonggen); i++)
	{
		if (zhonggen[i] == temp)
		{
			if (i - 1 >= 0)
			{
				return i - 1;
			}
			return -1;
		}
	}
	return -1;
}

int findright(char*zhonggen, char temp)                  //找有儿子
{
	for (int i = 0; i < strlen(zhonggen); i++)
	{
		if (zhonggen[i] == temp)
		{
			if (i + 1 < strlen(zhonggen))
			{
				return i + 1;
			}
			return -1;
		}
	}	
	return -1;
}

void digui(char*zhonggen,char*hougen,char*xiangen,int t,int now)
{
	if (t == -1||now==strlen(zhonggen)||xiangen[now]!='0') return;
	
	xiangen[now] = zhonggen[t];
	now++;

	digui(zhonggen, hougen, xiangen, findleft(zhonggen, xiangen[now - 1]), now);
	digui(zhonggen, hougen, xiangen, findright(zhonggen, xiangen[now - 1]), now);
}

int main()
{
	int now = 0,first;
	char tzhonggen[10], thougen[10], txiangen[10];
	in >> tzhonggen;
	in >> thougen;
	memset(txiangen, '0', sizeof(txiangen));
	for (int i = 0; i < strlen(tzhonggen); i++)
	{
		if (thougen[strlen(tzhonggen) - 1] == tzhonggen[i])
			first = i;
	}
	digui(tzhonggen, thougen, txiangen,first, now);
	for (int i = 0; i < strlen(tzhonggen); i++)
		out << txiangen[i];
}