#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
//coder:mortal
using namespace std;

const int Maxn = 5050;
char ch;
int st1[Maxn], cnt1, cnt2, num;
int prior[255];
LL st2[Maxn];

void clear() //初始化，为优先级赋值
{
	memset(st1, 0, sizeof(st1));
	memset(st2, 0, sizeof(st2));
	memset(prior, 0, sizeof(prior));
	cnt1 = 0; 
	cnt2 = 0;
	prior['+'] = 1; prior['-'] = 1;
	prior['*'] = 2; prior['/'] = 2;
}

void calc(char op)
{
	switch(op)
	{
		case'+': st2[cnt2-2] = st2[cnt2-2]+st2[cnt2-1]; cnt2--; break;
		case'-': st2[cnt2-2] = st2[cnt2-2]-st2[cnt2-1]; cnt2--; break;
		case'*': st2[cnt2-2] = st2[cnt2-2]*st2[cnt2-1]; cnt2--; break;
		case'/': st2[cnt2-2] = st2[cnt2-2]/st2[cnt2-1]; cnt2--; 
	}
}

void work(const char &ch)
{
	if (cnt1 == 0 || ch == '(' || prior[ch] > prior[st1[cnt1-1]])
	{
		st1[cnt1++] = ch;
	}
	else if (prior[ch] <= prior[st1[cnt1-1]] && ch != ')')
	{
		while (prior[ch] <= prior[st1[cnt1-1]] && cnt1 != 0)
		{
			calc(st1[cnt1-1]);
			cnt1--;
		}
		st1[cnt1++] = ch;
	}
	else if (ch == ')')
	{
		while(st1[cnt1-1] != '(')
		{
			calc(st1[cnt1-1]);
			cnt1--;
		}
		cnt1--;
	}
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	clear();
	while ((ch=getchar()) != '=') 
	{
		if (ch >= '0' && ch <= '9')
		{
			num = num * 10 + ch - '0';
		}
		else
		{
			if (num) 
			{
				st2[cnt2++] = num;
				num = 0;
			}
			work(ch);
		}
		/*for (int i = 0; i < cnt1; i++)
			printf("%c ", st1[i]);
		printf("\n");
		for (int i = 0; i < cnt2; i++)
			printf("%d ", st2[i]);
		printf("\n\n");*/
	}
	if (num) st2[cnt2++] = num;
	/*for (int i = 0; i < cnt1; i++)
		printf("%c ", st1[i]);
	printf("\n");
	for (int i = 0; i < cnt2; i++)
		printf("%d ", st2[i]);
	printf("\n");*/
	while (cnt1 != 0)
	{
		calc(st1[cnt1-1]); cnt1--;
	}
	printf("%I64d\n", st2[0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}