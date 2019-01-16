#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define operators_size 30
#define operand_size 20
char operators[operators_size];   //�����ջ
int operand[operand_size];      //�������ջ
int operators_top, operand_top;  //����ջ��
void push_operators(char operat)   //ѹ�������ջ����
{
	operators[operators_top] = operat;
	operators_top++;    //ѹ��һ�������֮�󣬽�ջ�������ƶ�һ��
}
char pop_operators()    //���������ջ����
{
	operators_top--;
	return operators[operators_top];
}
void push_operand(float operan)   //ѹ���������ջ����
{
	operand[operand_top] = operan;
	operand_top++;
}
int pop_operand()            //�����������ջ����
{
	operand_top--;
	return operand[operand_top];
}
void oper()
{
	int v1, v2, v;
	char op;
	//printf("����Ҫ���е������ǣ�%d %c %d\n", operand[operand_top - 2], operators[operators_top - 1], operand[operand_top - 1]);
	op = pop_operators();  //����һ�������
	v1 = pop_operand();     //���������������
	v2 = pop_operand();
	switch(op){
		case '+': v = v1 + v2; break;
		case '-': v = v2 - v1;
	//	          printf("���������� v1 = %d, v2 = %d, v = %d\n", v1, v2, v);
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
	push_operators('=');   //��=ѹ���������ջ
	ch = getchar();
	while(ch != '='){
		if(ch >= '0' && ch <= '9')//��������
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
	//				          printf("�շ���ķ���Ϊ��%c\n", ch);
							  break;
					case ')': while(operators[operators_top - 1] != '(') //��ȥ�����ţ��������������㣬ֱ���ҵ�������
									oper();
	//						  printf("�ո�ɾ���ķ���Ϊ��%c\n", operators[operators_top - 1]);
							  pop_operators(); //��������ɾ��
						      break;
					case '+':;
					case '-': while((operators[operators_top - 1] != '=') && (operators[operators_top - 1] != '('))//ֻ��'='��'('�ȼӺźͼ������ȼ��� ,��������ȼ��ȼ��Ÿߣ���ô��������
									oper();
							  push_operators(ch);
	//						  printf("�շ���ķ���Ϊ��%c\n", ch);
							  break;
					case '*':;
					case '/': while((operators[operators_top - 1] == '*') || (operators[operators_top - 1] == '/')) //���ȼ��ȳ��źͳ˺ŵ͵�
									oper();                                                                                                                //����Ҫ����
							  push_operators(ch);
	//						  printf("�շ���ķ���Ϊ��%c\n", ch);
							  break;
			}
			ch = getchar();
		}
	}
	while(operators[operators_top - 1] != '=')//��ʣ�µĲ���ȫ���������
	{
		oper();
	}
	printf("%d", operand[operand_top - 1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
