/*
	ѧ�ţ�55161123
	��ѧ�ţ�54160808
	����������� 
*/
/*
	����������
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
	�������ܣ��������������������ո����ķ��Ž��ж�Ԫ���㣬�����ؽ��
	���룺
		char operation:Ҫ���еķ��Ų���
		int a:��һ����������
		int b:�ڶ�����������
	�����
		a��b������Ӧ������ֵ
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
	�������ܣ��жϸ���������������ŵ����ȼ�
	���룺
		char a:��һ������
		char b:�ڶ�������
	�����
		���a���ŵ����ȼ����ڻ����b�����ȼ������true���������false
		�������aΪ'('��a�����ȼ���ͣ����false
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
	stack<char> operation;//�����������ջ
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char expr[1005]={NULL};//������ʽ������
	int num[1005]={0};//������������в����������飬������Ϻ��������num[0]��
	int p_expr=-1;//��������expr����
	int p_num=0;//��������num����
	scanf("%s",expr);
	while(expr[++p_expr]!='\0')//��ʼ���ζ�ȡ�ַ������м���
	{
		if(expr[p_expr]=='=')//�������ںţ�����ǰ�����е�ʽ��
		{
			while((p_num-1) != 0)
			{
				num[p_num-2]=cal(operation.top(),num[p_num-2],num[p_num-1]);
				num[--p_num]=0;
				operation.pop();
			}
		}
		else if(expr[p_expr]>='0' && expr[p_expr]<='9')//��ȡ����
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
		else if(expr[p_expr]=='(')//��ȡ������
		{
			operation.push('(');
			continue;
		}
		else if(!operation.empty() && expr[p_expr]!=')' && judgeHigher(operation.top(),expr[p_expr]))//����ջ������ջ����Ϊ��������������ȼ����ұ߸߻���ȣ���ʱ���м���
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
		else if((!operation.empty() && !judgeHigher(operation.top(),expr[p_expr])) || (operation.empty() && !expr[p_expr]!='='))//����ջΪ�ջ�������ȼ����ұߵͣ���ʱ������ѹջ
		{
			operation.push(expr[p_expr]);
			continue;
		}
		else if(!operation.empty() && expr[p_expr]==')')//���������ţ����������ڵ�ʽ��
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
	printf("%d",num[0]);//���������
	fclose(stdin);
	fclose(stdout);
	return 0;
}