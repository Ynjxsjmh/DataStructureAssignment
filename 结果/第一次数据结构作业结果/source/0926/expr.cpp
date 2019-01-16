
#include<stack>                  //用STL模板
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int suffixvalue(char infix[]);   //将中缀表达式转化为后缀并求值
int main()
{
	FILE *fpin, *fpout;
	freopen( "expr.in", "r",stdin);
	freopen("expr.out", "w", stdout);
	char infix[1005];              //定义大于1000的字符串
	cout << "请输入中缀表达式，不能有空格哟！！括号用英文哟！！，以‘=’结尾：" << endl;
	cin >> infix;                  //遇到空格或回车不能读入,以\0结尾
	cout << "对应的后缀表达式的值为：" << suffixvalue(infix) << endl;
	fclose(stdin);//关闭文件
	fclose(stdout);//关闭文件
	return 0;

}
int suffixvalue(char infix[])
{
	int i = 0, x = 0; int a = 0, b = 0,c = 0;//a,b,c用于数值计算；x用于将多位数字字符转化为数字后压栈，i用于计数
	stack<int>s; stack<char>stack;           //用两个栈，一个放符号，一个放数据
	for(;infix[i] != '=' ;i++)
	{
		//将数字字符压栈
		if (infix[i] >= '0' && infix[i] <= '9')
		{
			//循环将数字字符转化为数字
			while (infix[i] >= '0' && infix[i] <= '9')
			{
				x = x * 10 + (infix[i] - '0'); i++;
			}
			s.push(x); x = 0; i--;
		}





		//如果是-+
		else if (infix[i] == '+' || infix[i] == '-')
		{
			//如果是空或（则压栈
			if (stack.empty() || stack.top() == '(' )
			{
				stack.push(infix[i]);
			}
			//否则 前面的可以计算 直到为空或遇到（
			else
			{
				while ( stack.size() && stack.top() != '(')
				{
                  // 弹出数字栈中的两个数字并进行相应的计算
					for (int j = 0; j < 2; j++)
						if (s.size())
						{
							if (j == 0)a = s.top();
							if (j == 1)b = s.top();
							s.pop();
						}
						else
						{
							cout << "你所给的表达式有错"  << endl;  //栈中如果元素<2一定出错
							system("pause"); exit(1);
						}
					if (stack.top() == '+')
						c = a + b;
					else if (stack.top() == '-')
						c = b - a;
					else if (stack.top() == '*')
						c = a*b;
					else if (stack.top() == '/')
						if (a)
							c = b / a;
						else
						{
							cout << "除数不能为零啊！"  << endl;  //判断除数不为零
							system("pause"); exit(1);
						}
					s.push(c);
					stack.pop();


				}stack.push(infix[i]);   //最后再将+-压栈

			}
		}
		//如果是*或者/
		else if (infix[i] == '*' || infix[i] == '/')
		{
			//前面是空或+或-或（都进行将* /压栈
			if (stack.empty() || stack.top() == '+' || stack.top() == '-' || stack.top() == '(')
			{
				stack.push(infix[i]);
			}
			//否则只讲前面的   *  /进行计算，因为前面不可能有多个*  /， 所以这里不用像 +  -一样判断是否到（或空
			else
			{
				//数据栈中弹出两个数据
				for (int j = 0; j<2; j++)
					if (s.size())
					{
						if (j == 0)a = s.top();
						if (j == 1)b = s.top();
						s.pop();
					}
					else
					{
						cout << "你所给的表达式有错" << endl;
						system("pause"); exit(1);
					}
				if (stack.top() == '*')
					c = a*b;
			    if(stack.top() == '/')
					if (a)
						c = b / a;
					else
					{
						cout << "除数不能为零啊！" << endl;  //判断除数不为零
						system("pause"); exit(1);
					}
				s.push(c);   //将算好的数字压栈
				stack.pop();  //弹出被用于计算的运算符
				stack.push(infix[i]);   //将* /压栈
			}
		}
		//如果是（则直接压栈
		else if (infix[i] == '(' )
		{
			stack.push(infix[i]);
		}
		//如果是）则弹栈直到遇到（
		else if (infix[i] == ')')
		{
			while (stack.size() && stack.top() != '(')//前后顺序不能颠倒，如果栈空了，则stack.top的值是多少，这样程序会报错
			{     //弹出两个数据
					for (int j = 0; j<2; j++)
						if (s.size())
						{
							if (j == 0)a = s.top();
							if (j == 1)b = s.top();
							s.pop();
						}
						else
						{
							cout << "你所给的表达式有错" << endl;
							system("pause"); exit(1);
						}
					//运算
					if (stack.top() == '+')
						c = a + b;
					else if (stack.top() == '-')
						c = b - a;
					else if (stack.top() == '*')
						c = a*b;
					else if (stack.top() == '/')
						if (a)
							c = b / a;
						else
						{
							cout << "除数不能为零啊！" << endl;//判断除数
							system("pause"); exit(1);
						}
					s.push(c);
					stack.pop();
			}
			if (stack.empty())   //说明无左括号则一定错误
			{
				cout << "你所给的表达式有错" << endl;
				system("pause"); exit(1);
			}
			//这时只需弹出（
			else
				stack.pop();
		}

		//如果是其他字符
		else
		{
			cout << "你所给的表达式含有不该有的字符啊！"<< endl;
			system("pause"); exit(1);
		}
	}
	//如果=后还有其他字符则提示出错
	if(infix[i+1]!='\0')
	{
		cout << "你所给的表达式'='后为啥含有不该有的字符啊！" << endl;
		system("pause"); exit(1);
	}
	//最后将运算符栈中的元素弹出
	while (stack.size())
		{
			for (int j = 0; j<2; j++)
				if (s.size())
				{
					if (j == 0)a = s.top();
					if (j == 1)b = s.top();
					s.pop();
				}
				else
				{
					cout << "你所给的表达式有错" << endl;
					system("pause");	exit(1);
				}
			if (stack.top() == '+')
				c = a + b;
			else if (stack.top() == '-')
				c = b - a;
			else if (stack.top() == '*')
				c = a*b;
			else if (stack.top() == '/')
				if (a)
					c = b / a;
				else
				{
					cout << "除数不能为零啊！" << endl;
					system("pause"); exit(1);
				}
			else
			{
				cout << "你所给的表达式不对啊！"  << endl;
				system("pause"); exit(1);
			}
			s.push(c);
			stack.pop();
		}
	//字符栈中元素为空时，但数据却不是一个，则所给的表达式一定有问题；
		if (stack.empty() && s.size() != 1)
		{
			cout << "你所给的表达式不对啊！"  << endl;
			system("pause"); exit(1);
		}
   //如果字符栈为空时且数据栈且只有一个，最后运算结果一定是它；
		else if (stack.empty() && s.size() == 1)
		{
			return s.top();
		}
	//这里先用stack.size再用stack.empty一举两得
	//一方面，如果有字符栈元素最后运算后结果仍与最后空时一样；
	//另一方面，如果字符栈为空时，直接判断数据栈；
}

























