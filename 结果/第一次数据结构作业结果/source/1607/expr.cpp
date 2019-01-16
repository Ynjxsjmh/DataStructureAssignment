#include<stdio.h>
#include<string.h>
long long num[10000];
char mark[10000];
char ch[10000];
long long list[1000];
long long loca;

long long find(long long i, long long len)
{
	long long sum;
	sum = 0;
	for( ; i < len ; i++)
	{
		if(ch[i] < '0' || ch[i] > '9')
		{
			loca = i - 1;
			return sum;
		}
		sum *= 10;
		sum += ch[i] - '0';
	}
	return sum;
}

long long loading()
{
	list['='] = 0;
	list[')'] = 1;
	list['+'] = 3;
	list['-'] = 3;
	list['*'] = 4;
	list['/'] = 4;
	list['('] = 5;
	return 0;
}

long long solve(long long a,long long b,char c)
{
	if(c == '+')return a+b;
	if(c == '-')return a-b;
	if(c == '*')return a*b;
	if(c == '/')return a/b;
}

int main()
{
	long long n,m,i,j,len,sum;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	loading();
	scanf("%s",ch);
	len = strlen(ch);
	for(i = 0; i < len; i++)
	{
		if(ch[i] >= '0' && ch[i] <= '9')
		{
			sum = find(i, len);
			i = loca;
			num[++num[0]] = sum;
		}
		else
		{
			while(mark[0] != 0 && list[mark[mark[0]]] >= list[ch[i]])
			{
				if(mark[mark[0]] != '(')
				{
					sum = solve(num[num[0]-1],num[num[0]],mark[mark[0]]);
					num[--num[0]] = sum;
					mark[0]--;
				}
				else
				{
					if(ch[i] == ')')mark[0]--;
					break;
				}
			}
			if(ch[i] != ')')
				mark[++mark[0]] = ch[i];
		}
	}
	printf("%I64d",num[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}