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
float hanshu1(float a,float b,char c)//进去的不一定是整数
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
			s.push(temp);// if(!t.empty()){cout<<t.top()<<"哈哈";}
		//	cout<<s.top()<<"\n";
			c[0] = '\0';
			i = 0;
		}

		if(*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			if(t.empty())
			{t.push(*p);//cout<<*p<<"\n";//这边的话因为*p一旦压栈就必须走下一位，所以这一句必须和下一句括在一起
			p++;}//cout<<(*p)<<"\n";}
			if(!t.empty()){//我加的  必须满足这个条件
			while(*p == '+' || *p == '-')//这个必须在不满足空栈的时候才能执行   因为这里面要用到s.top()比较  如果空栈的 话  是无法比较的  会出错  但不报错  要记住
			{//cout<<"h啊啊\n";
				
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
				s.push(r);//这一段之所以这样写 是因为+ - 号不会再遇到比他等级更低的等级符号了  所以 
				
				if(t.empty())
				{
					t.push(*p);
					p++;
				}
			}
			}
			while((*p =='*') ||( *p =='/'))
			{//cout<<*p<<"h啊啊\n";
			
				if(t.top() == '(')
				{
				//	printf("呵呵呵\n");
					t.push(*p);
					p++;
					break;
				}
				if((t.top()=='+') ||( t.top()== '-'))
				{//printf("呵呵呵\n");
					t.push(*p);//cout<<*p <<"hahah\n";
					p++;break;//刚才困在这困几个小时  就在这   不加个break的话   会继续执行下个if
				}
			/*	m = s.top();s.pop();
				n = s.top();s.pop();
				o = t.top();t.pop();
				r = hanshu1(m,n,o);
				s.push(r);*///这一段是啥    是不是少下面一种情况
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
		{t.push(*p);//加括号
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
	while(!t.empty())//指针p走到结尾不代表栈内已经运算完   所以要不停的进行弹栈运算    直到符号栈为空
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
//刁大佬改了三个半小时呢，你要好好学习哟
