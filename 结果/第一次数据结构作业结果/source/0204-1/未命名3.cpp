#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
float hanshu1(float a,float b,char c)//��ȥ�Ĳ�һ��������
{
	if(c == '+')
		return a + b;
	else if(c == '-')
		return b - a;
	else if(c == '*')
		return a * b;
	else if(c == '/')
		return (b * 1.0) / a;
}
float hanshu2(char * p)
{
	stack <float> s;
	stack <char> t;
	float m,n;
	float r;
	char o;
	char c[10];
	int i = 0;
	int temp;
	while(*p != '=')
	{//cout<<*p<<"\n";
		//if(!s.empty()){
		//	cout<<s.top()<<"haha\n";}

		if(*p >= '0' && *p <= '9')
		{
			
			c[0] = *p;
			p++;
			while(*p >= '0' && *p <= '9')
			{
				c[i + 1] = *p;
				p++;
				i++;
			}
			c[i + 1] = '\0';
			temp = atoi(c);
			s.push(temp);// if(!t.empty()){cout<<t.top()<<"����";}
		//	cout<<s.top()<<"\n";
			c[0] = '\0';
			i = 0;
		}

		if(*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			if(t.empty())
			{t.push(*p);//cout<<*p<<"\n";//��ߵĻ���Ϊ*pһ��ѹջ�ͱ�������һλ��������һ��������һ������һ��
			p++;}//cout<<(*p)<<"\n";}
			if(!t.empty()){//�Ҽӵ�  ���������������
			while(*p == '+' || *p == '-')//��������ڲ������ջ��ʱ�����ִ��   ��Ϊ������Ҫ�õ�s.top()�Ƚ�  �����ջ�� ��  ���޷��Ƚϵ�  �����  ��������  Ҫ��ס
			{//cout<<"h����\n";
				
				if(t.top()=='(')
				{
					t.push(*p);
					p++;
					break;
				}
				
				m = s.top();s.pop();
				n = s.top();s.pop();
				o = t.top();t.pop();
				r = hanshu1(m,n,o);
				s.push(r);//��һ��֮��������д ����Ϊ+ - �Ų��������������ȼ����͵ĵȼ�������  ���� 
				
				if(t.empty())
				{
					t.push(*p);
					p++;
				}
			}
			}
			while((*p =='*') ||( *p =='/'))
			{//cout<<*p<<"h����\n";
			
				if(t.top() == '(')
				{
				//	printf("�ǺǺ�\n");
					t.push(*p);
					p++;
					break;
				}
				if((t.top()=='+') ||( t.top()== '-'))
				{//printf("�ǺǺ�\n");
					t.push(*p);//cout<<*p <<"hahah\n";
					p++;break;//�ղ�������������Сʱ  ������   ���Ӹ�break�Ļ�   �����ִ���¸�if
				}
			/*	m = s.top();s.pop();
				n = s.top();s.pop();
				o = t.top();t.pop();
				r = hanshu1(m,n,o);
				s.push(r);*///��һ����ɶ    �ǲ���������һ�����
				if((t.top()=='*')||(t.top()=='/'))
				{//	cout<<t.top()<<"ssss";cout<<*p<<"hehngh"<<"\n";
					m = s.top();//cout<<s.top();
					s.pop();
				n = s.top();//cout<<s.top();
				s.pop();
				o = t.top();//cout<<t.top();
				t.pop();
				r = hanshu1(m,n,o);
			//	cout<<r<<"\n";
				s.push(r);
				}
				if(t.empty())
				{
					t.push(*p);
					p++;
				}
			}
		}
		if(*p == '(')
		{t.push(*p);//������
		p++;}
		if(*p == ')')
		{
			while((*p == ')')&&(t.top() != '('))
			{
				m = s.top();s.pop();
				n = s.top();s.pop();
				o = t.top();t.pop();
				r = hanshu1(m,n,o);
				s.push(r);
			}
			t.pop();
			p++;
		}
	}
	while(!t.empty())//ָ��p�ߵ���β������ջ���Ѿ�������   ����Ҫ��ͣ�Ľ��е�ջ����    ֱ������ջΪ��
	{
			m = s.top();s.pop();
				n = s.top();s.pop();
				o = t.top();t.pop();
				r = hanshu1(m,n,o);
				s.push(r);//cout<<s.top();
		//		cout<<r<<"\n";
	}
	return s.top();
}
ifstream fin("expr.in");
ofstream fout("expr.out");
int main(void)
{
	
	char a[1000];
	cin>>a;
	FILE *f1,*f2;
	float result;
	result = hanshu2(a);
	cout<<result<<"\n";
	return 0;
}
//����и���������Сʱ�أ���Ҫ�ú�ѧϰӴ
