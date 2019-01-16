
#include<stack>                  //��STLģ��
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int suffixvalue(char infix[]);   //����׺���ʽת��Ϊ��׺����ֵ
int main()
{
	FILE *fpin, *fpout;
	freopen( "expr.in", "r",stdin);
	freopen("expr.out", "w", stdout);
	char infix[1005];              //�������1000���ַ���
	cout << "��������׺���ʽ�������пո�Ӵ����������Ӣ��Ӵ�������ԡ�=����β��" << endl;
	cin >> infix;                  //�����ո��س����ܶ���,��\0��β
	cout << "��Ӧ�ĺ�׺���ʽ��ֵΪ��" << suffixvalue(infix) << endl;
	fclose(stdin);//�ر��ļ�
	fclose(stdout);//�ر��ļ�
	return 0;

}
int suffixvalue(char infix[])
{
	int i = 0, x = 0; int a = 0, b = 0,c = 0;//a,b,c������ֵ���㣻x���ڽ���λ�����ַ�ת��Ϊ���ֺ�ѹջ��i���ڼ���
	stack<int>s; stack<char>stack;           //������ջ��һ���ŷ��ţ�һ��������
	for(;infix[i] != '=' ;i++)
	{
		//�������ַ�ѹջ
		if (infix[i] >= '0' && infix[i] <= '9')
		{
			//ѭ���������ַ�ת��Ϊ����
			while (infix[i] >= '0' && infix[i] <= '9')
			{
				x = x * 10 + (infix[i] - '0'); i++;
			}
			s.push(x); x = 0; i--;
		}





		//�����-+
		else if (infix[i] == '+' || infix[i] == '-')
		{
			//����ǿջ���ѹջ
			if (stack.empty() || stack.top() == '(' )
			{
				stack.push(infix[i]);
			}
			//���� ǰ��Ŀ��Լ��� ֱ��Ϊ�ջ�������
			else
			{
				while ( stack.size() && stack.top() != '(')
				{
                  // ��������ջ�е��������ֲ�������Ӧ�ļ���
					for (int j = 0; j < 2; j++)
						if (s.size())
						{
							if (j == 0)a = s.top();
							if (j == 1)b = s.top();
							s.pop();
						}
						else
						{
							cout << "�������ı��ʽ�д�"  << endl;  //ջ�����Ԫ��<2һ������
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
							cout << "��������Ϊ�㰡��"  << endl;  //�жϳ�����Ϊ��
							system("pause"); exit(1);
						}
					s.push(c);
					stack.pop();


				}stack.push(infix[i]);   //����ٽ�+-ѹջ

			}
		}
		//�����*����/
		else if (infix[i] == '*' || infix[i] == '/')
		{
			//ǰ���ǿջ�+��-�򣨶����н�* /ѹջ
			if (stack.empty() || stack.top() == '+' || stack.top() == '-' || stack.top() == '(')
			{
				stack.push(infix[i]);
			}
			//����ֻ��ǰ���   *  /���м��㣬��Ϊǰ�治�����ж��*  /�� �������ﲻ���� +  -һ���ж��Ƿ񵽣����
			else
			{
				//����ջ�е�����������
				for (int j = 0; j<2; j++)
					if (s.size())
					{
						if (j == 0)a = s.top();
						if (j == 1)b = s.top();
						s.pop();
					}
					else
					{
						cout << "�������ı��ʽ�д�" << endl;
						system("pause"); exit(1);
					}
				if (stack.top() == '*')
					c = a*b;
			    if(stack.top() == '/')
					if (a)
						c = b / a;
					else
					{
						cout << "��������Ϊ�㰡��" << endl;  //�жϳ�����Ϊ��
						system("pause"); exit(1);
					}
				s.push(c);   //����õ�����ѹջ
				stack.pop();  //���������ڼ���������
				stack.push(infix[i]);   //��* /ѹջ
			}
		}
		//����ǣ���ֱ��ѹջ
		else if (infix[i] == '(' )
		{
			stack.push(infix[i]);
		}
		//����ǣ���ջֱ��������
		else if (infix[i] == ')')
		{
			while (stack.size() && stack.top() != '(')//ǰ��˳���ܵߵ������ջ���ˣ���stack.top��ֵ�Ƕ��٣���������ᱨ��
			{     //������������
					for (int j = 0; j<2; j++)
						if (s.size())
						{
							if (j == 0)a = s.top();
							if (j == 1)b = s.top();
							s.pop();
						}
						else
						{
							cout << "�������ı��ʽ�д�" << endl;
							system("pause"); exit(1);
						}
					//����
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
							cout << "��������Ϊ�㰡��" << endl;//�жϳ���
							system("pause"); exit(1);
						}
					s.push(c);
					stack.pop();
			}
			if (stack.empty())   //˵������������һ������
			{
				cout << "�������ı��ʽ�д�" << endl;
				system("pause"); exit(1);
			}
			//��ʱֻ�赯����
			else
				stack.pop();
		}

		//����������ַ�
		else
		{
			cout << "�������ı��ʽ���в����е��ַ�����"<< endl;
			system("pause"); exit(1);
		}
	}
	//���=���������ַ�����ʾ����
	if(infix[i+1]!='\0')
	{
		cout << "�������ı��ʽ'='��Ϊɶ���в����е��ַ�����" << endl;
		system("pause"); exit(1);
	}
	//��������ջ�е�Ԫ�ص���
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
					cout << "�������ı��ʽ�д�" << endl;
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
					cout << "��������Ϊ�㰡��" << endl;
					system("pause"); exit(1);
				}
			else
			{
				cout << "�������ı��ʽ���԰���"  << endl;
				system("pause"); exit(1);
			}
			s.push(c);
			stack.pop();
		}
	//�ַ�ջ��Ԫ��Ϊ��ʱ��������ȴ����һ�����������ı��ʽһ�������⣻
		if (stack.empty() && s.size() != 1)
		{
			cout << "�������ı��ʽ���԰���"  << endl;
			system("pause"); exit(1);
		}
   //����ַ�ջΪ��ʱ������ջ��ֻ��һ�������������һ��������
		else if (stack.empty() && s.size() == 1)
		{
			return s.top();
		}
	//��������stack.size����stack.emptyһ������
	//һ���棬������ַ�ջԪ��������������������ʱһ����
	//��һ���棬����ַ�ջΪ��ʱ��ֱ���ж�����ջ��
}

























