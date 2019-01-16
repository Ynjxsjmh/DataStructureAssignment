#include<iostream>
#include<cstring>
using namespace std;

void preorder(char* zhong, char* hou, int l)
{
	if (l <= 0)
	{
		return;
	}
	char son_h1[10], son_h2[10], son_z1[10], son_z2[10];
	int i,loc;
	char c = hou[l - 1];
	cout << c;
	for (i = 0; i < 10; i++)
	{
		if (zhong[i] != c)
		{
			son_z1[i] = zhong[i];
		}
		else
		{
			break;
		}
	}
	loc = i;
	for (i = 0; i < loc; i++)
	{
		son_h1[i] = hou[i];
	}
	for (i = loc + 1; i < l; i++)
	{
		son_z2[i-loc-1] = zhong[i];
	}
	for (i = loc; i < l - 1; i++)
	{
		son_h2[i-loc] = hou[i];
	}
	son_z1[loc] = son_h1[loc] = '\0';
	son_z2[l - loc - 1] = son_h2[l - loc - 1] = '\0';
	preorder(son_z1, son_h1, loc);
	preorder(son_z2, son_h2, l - loc - 1);
}

int main()
{
	freopen("preorder.in", "r", stdin);
	freopen("preorder.out", "w", stdout);
	char str1[10];
	char str2[10];
	scanf("%s", str1);
	scanf("%s", str2);
	preorder(str1, str2, strlen(str1));
}
