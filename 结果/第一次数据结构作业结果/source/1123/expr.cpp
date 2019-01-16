/*
	学号：55161123
	教学号：54160808
	姓名：窦星磊 
*/
/*
	测试用例：
	2+3-(6*2)/3+(5*(3+1)-2)=					(19)
	(((1+101)/2+9)/2-10*2+101)*2+222*2-66=		(600)
	(12345678+87654321)/9/100*100=				(11111100)
	5*(6-2*3)+6-(23*2-47)*(31/3)=				(16)
	(1+30)/3=									(10)
	5*(3-2)-4=									(1)
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

/*
	函数功能：将给出的两个整数按照给出的符号进行二元运算，并返回结果
	输入：
		char operation:要进行的符号操作
		int a:第一个待处理数
		int b:第二个待处理数
	输出：
		a与b进行相应运算后的值
*/
int cal(char operation,int a,int b)
{
	if(operation=='+')
			return a+b;
	if(operation=='-')
			return a-b;
	if(operation=='*')
			return a*b;
	if(operation=='/')
			return a/b;
}

/*
	函数功能：判断给出的两个运算符号的优先级
	输入：
		char a:第一个符号
		char b:第二个符号
	输出：
		如果a符号的优先级高于或等于b的优先级，输出true，否则输出false
		如果符号a为'('，a的优先级最低，输出false
*/
bool judgeHigher(char a,char b)
{
	if (a=='(') return false;
	int rank1,rank2;
	if(a=='*'||a=='/')
		rank1=1;
	else if(a=='+'||a=='-')
		rank1=0;
	if(b=='*'||b=='/')
		rank2=1;
	else if(b=='+'||b=='-')
		rank2=0;
	return rank1>=rank2;
}

int main(void)
{
	stack<char> operation;//储存操作符的栈
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char expr[1005]={NULL};//储存表达式的数组
	int num[1005]={0};//储存运算过程中产生数的数组，计算完毕后结果存放在num[0]中
	int p_expr=-1;//用来操作expr数组
	int p_num=0;//用来操作num数组
	scanf("%s",expr);
	while(expr[++p_expr]!='\0')//开始依次读取字符并进行计算
	{
		if(expr[p_expr]=='=')//遇到等于号，计算前面所有的式子
		{
			while((p_num-1) != 0)
			{
				num[p_num-2]=cal(operation.top(),num[p_num-2],num[p_num-1]);
				num[--p_num]=0;
				operation.pop();
			}
		}
		else if(expr[p_expr]>='0' && expr[p_expr]<='9')//读取数字
		{
			while(expr[p_expr]>='0' && expr[p_expr]<='9')
			{
				num[p_num]=num[p_num]*10+(expr[p_expr]-'0');
				p_expr++;
			}			
			p_expr--;
			p_num++;
			continue;
		}
		else if(expr[p_expr]==')' && operation.top()=='(')
		{
			operation.pop();
		}
		else if(expr[p_expr]=='(')//读取左括号
		{
			operation.push('(');
			continue;
		}
		else if(!operation.empty() && expr[p_expr]!=')' && judgeHigher(operation.top(),expr[p_expr]))//符号栈不空且栈顶不为左括号且左边优先级比右边高或相等，此时进行计算
		{
			while(!operation.empty() && operation.top()!='(' && judgeHigher(operation.top(),expr[p_expr]))
			{
				num[p_num-2]=cal(operation.top(),num[p_num-2],num[p_num-1]);
				num[--p_num]=0;
				operation.pop();		
				if(operation.empty() || (!operation.empty() && !judgeHigher(operation.top(),expr[p_expr])))
				{
					operation.push(expr[p_expr]);
					break;
				}
			}
			continue;
		}
		else if((!operation.empty() && !judgeHigher(operation.top(),expr[p_expr])) || (operation.empty() && !expr[p_expr]!='='))//符号栈为空或左边优先级比右边低，此时将符号压栈
		{
			operation.push(expr[p_expr]);
			continue;
		}
		else if(!operation.empty() && expr[p_expr]==')')//遇到右括号，计算括号内的式子
		{
			while(operation.top()!='(')
			{
				num[p_num-2]=cal(operation.top(),num[p_num-2],num[p_num-1]);
				num[--p_num]=0;
				operation.pop();
			}
			operation.pop();
			continue;
		}
	}
	printf("%d",num[0]);//输出计算结果
	fclose(stdin);
	fclose(stdout);
	return 0;
}