#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define operators_size 30
#define operand_size 20
char operators[operators_size];   //运算符栈
int operand[operand_size];      //运算分量栈
int operators_top, operand_top;  //声明栈顶
void push_operators(char operat)   //压入运算符栈函数
{
	operators[operators_top] = operat;
	operators_top++;    //压入一个运算符之后，将栈顶向上移动一个
}
char pop_operators()    //弹出运算符栈函数
{
	operators_top--;
	return operators[operators_top];
}
void push_operand(float operan)   //压入运算分量栈函数
{
	operand[operand_top] = operan;
	operand_top++;
}
int pop_operand()            //弹出运算分量栈函数
{
	operand_top--;
	return operand[operand_top];
}
void oper()
{
	int v1, v2, v;
	char op;
	//printf("马上要进行的运算是：%d %c %d\n", operand[operand_top - 2], operators[operators_top - 1], operand[operand_top - 1]);
	op = pop_operators();  //弹出一个运算符
	v1 = pop_operand();     //弹出两个运算分量
	v2 = pop_operand();
	switch(op){
		case '+': v = v1 + v2; break;
		case '-': v = v2 - v1;
	//	          printf("啊啊啊啊啊 v1 = %d, v2 = %d, v = %d\n", v1, v2, v);
				  break;
		case '*': v = v1 * v2; break;
		case '/': v = v2 / v1; break;
	}
	//printf("v=%d\n", v);
	push_operand(v);
}
int main(void)
{
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
	char ch, zifu[1000];
	int i = 0, j;
	int s = 0;
	operators_top = 0;
	operand_top = 0;
	push_operators('=');   //将=压入运算符号栈
	ch = getchar();
	while(ch != '='){
		if(ch >= '0' && ch <= '9')//处理数字
		{
			zifu[i++] = ch;
			ch = getchar();
			if((ch < '0' || ch > '9') && (i != 0))
			{
				j = i;
				while(i)
				{
					s = s + (zifu[--i] - '0') * pow(10, j - i - 1);
				}
				push_operand(s);
	//			printf("s=%d\n", s);
				s = 0;
			}
		}
		else
		{
			switch(ch){
					case '(': push_operators(ch);
	//				          printf("刚放入的符号为：%c\n", ch);
							  break;
					case ')': while(operators[operators_top - 1] != '(') //进去右括号，进行括号内运算，直到找到左括号
									oper();
	//						  printf("刚刚删除的符号为：%c\n", operators[operators_top - 1]);
							  pop_operators(); //将左括号删除
						      break;
					case '+':;
					case '-': while((operators[operators_top - 1] != '=') && (operators[operators_top - 1] != '('))//只有'='与'('比加号和减号优先级低 ,如果是优先级比减号高，那么进行运算
									oper();
							  push_operators(ch);
	//						  printf("刚放入的符号为：%c\n", ch);
							  break;
					case '*':;
					case '/': while((operators[operators_top - 1] == '*') || (operators[operators_top - 1] == '/')) //优先级比除号和乘号低的
									oper();                                                                                                                //均需要运算
							  push_operators(ch);
	//						  printf("刚放入的符号为：%c\n", ch);
							  break;
			}
			ch = getchar();
		}
	}
	while(operators[operators_top - 1] != '=')//把剩下的操作全部进行完毕
	{
		oper();
	}
	printf("%d", operand[operand_top - 1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
