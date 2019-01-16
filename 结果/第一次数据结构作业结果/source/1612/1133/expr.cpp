#include<stdio.h>
#include<stack>
using namespace std;
//num为操作数栈，ch为运算符栈
//x用于存储输入的字符,
//i为当x是操作数时的位数记录器、s用于存储各位数
stack<int>num;
stack<char>ch;
void cal(int t1,int t2)
{
	t2=num.top();
	num.pop();
	t1=num.top();
	num.pop();
	switch(ch.top())
	{
		case '*':
			num.push(t1*t2);
			break;
		case '/':
			num.push(t1/t2);
			break;
		case '+':
			num.push(t1+t2);
			break;
		case '-':
			num.push(t1-t2);
			break;
	}
	ch.pop();//top和pop配套使用
}
int prio(char x)
{
	switch(x)
	{
		case '(':
			return 0;
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
	}
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
	while(1)
	{
		char x;
		int i=0,flag=0;
		scanf("%c",&x);
		int t=0;
		while (x<='9' && x>='0') {
			flag=1;
			t=t*10+x-'0';
			scanf("%c",&x);
		}
		if (flag) {
			num.push(t);
		}
		//当x是运算符时
		if(x>='('&&x<='/')
		{
		    if (x==')') {
                while(ch.top()!='(')
				{
					int t1,t2;
					cal(t1,t2);
				}
				ch.pop();
		    }
			else if(ch.empty()||x=='('||prio(x)>prio(ch.top()))
				ch.push(x);
			else
			{
				while(!ch.empty()&&prio(x)<=prio(ch.top()))
				{
					int t1,t2;
					cal(t1,t2);
				}
				ch.push(x);
			}
		}
		if(x=='=')
		{
			int t1,t2;
			while(!ch.empty())
			{
				cal(t1,t2);
			}
			printf("%d\n",num.top());
			return 0;
		}

	}
	fclose(stdin); fclose(stdout);
	return 0;
}
