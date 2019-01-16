#include<stdio.h>
#include<string.h>
#define maxm 1000
char alls[maxm+5];
char operators[maxm+5];
long long numbers[maxm+5];
long long ft;
long long ft1;//符号伪指针 
long long ft2;//数字伪指针 
long long change(long long p)//将char字符转化为int数字 
{
	long long n = alls[p++] - 48;
	while(alls[p]<='9'&&alls[p]>='0')
	{
		n = n*10 + alls[p++] - 48;	
	}
	numbers[ft2++] = n;
	return p;
}
long long value(char a)
{
	if(a == '+' || a == '-') return 1;
	if(a == '*' || a == '/') return 2;
	if(a == '(') return 0;
	if(a == ')') return 3;
 } 
long long count(long long a,long long b,char c)
{
	if(c == '+')	return a+b;
	if(c == '-')	return a-b;
	if(c == '*')	return a*b;
	if(c == '/')	return a/b;
} 
void solve()
{
	ft = 0;
	ft1 = 0;
	ft2 = 0;
	while(alls[ft]!='='){
		if(alls[ft] <= '9' && alls[ft] >= '0')//数字 
			ft = change(ft);
		else
		{	
			if( (  value(alls[ft]) > value(operators[ft1 - 1])   &&alls[ft]!=')' )|| ft1 == 0 || alls[ft] == '(' )//字符入栈条件	
				operators[ft1++] = alls[ft++];
			else
			{
				while( value(alls[ft]) <= value(operators[ft1 - 1]) && ft1 > 0 && ft2>=2 && alls[ft]!='(')//计算条件1 
				{
					numbers[ft2-2] = count(numbers[ft2 - 2],numbers[ft2 - 1],operators[ft1-1]);
					ft2--;ft1--;
				}
			} 
			if( alls[ft] == ')' )//计算条件2 
			{ 
				while(operators[ft1-1]!='(')
				{
					numbers[ft2-2] = count(numbers[ft2-2],numbers[ft2 - 1],operators[ft1-1]);
					ft2--;ft1--;
				} 
				ft1--;
				ft++;
			} 
		}
	}
	while(ft1!=0)//最终计算 
	{
		numbers[ft2-2] = count(numbers[ft2-2],numbers[ft2-1],operators[ft1-1]);
		ft2--;ft1--;
	}
}
int main()
{
	freopen ("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",alls);
	solve();
	printf("%I64d",numbers[ft2-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
