#include<stdio.h>
#include<stack.h>
stack<char> fh;
stack<int> shu;
using namespace std;
void jisuan(int level)
{
	int a,b;
	if(fh.top()=='*'&&level>0)
	{
		a=shu.top();
		shu.pop();
		b=shu.top();
		shu.pop();
		fh.pop();
		shu.push(b*a);
	}
	else if(fh.top()=='/'&&level>0)
	{
		a=shu.top();
		shu.pop();
		b=shu.top();
		shu.pop();
		fh.pop();
		shu.push(b/a);
	}
	else if(fh.top()=='+'&&level>1)
	{
		a=shu.top();
		shu.pop();
		b=shu.top();
		shu.pop();
		fh.pop();
		shu.push(b+a);
	}
	else if(fh.top()=='-'&&level>1)
	{
		a=shu.top();
		shu.pop();
		b=shu.top();
		shu.pop();
		fh.pop();
		shu.push(b-a);
	}
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int num=-1,flag=0;
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c>='0'&&c<='9')
		{
			if(num==-1)num=c-'0';
			else num=num*10+c-'0';
		}
		else
		{
			if(num!=-1)
			{
				shu.push(num);
				num=-1;
			}
			if(c=='+'||c=='-')
			{
				while(fh.size()!=0&&fh.top()!='(')
				{
					jisuan(2);
				}
				fh.push(c);
			}
			else if(c=='*'||c=='/')
			{
				while(fh.size()!=0)
				{
					if(fh.top()=='+'||fh.top()=='-'||fh.top()=='(')break;
					jisuan(1);
				}
				fh.push(c);
			}
			else if(c=='(')
			{
				fh.push(c);
			}
			else if(c==')')
			{
				while(fh.top()!='(')
				{
					jisuan(2);
				}
				fh.pop();
				while(fh.size()!=0)
				{
					if(fh.top()=='+'||fh.top()=='-'||fh.top()=='(')break;
					jisuan(1);
				}
			}
			else if(c=='=')
			{
				while(fh.size()!=0)
				{
					jisuan(2);
				}
				int ans=shu.top();
				printf("%d",ans);
				return 0;
			}
		}
	}
	return 0;
}
