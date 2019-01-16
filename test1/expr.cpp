#include <stdio.h>
#include <string.h>
#include <stdlib.h>

template <typename T>
class zstack{
	private:
		int top;
		int len;
		T *stack;
	public:
		zstack(int length){
			stack=new T[length];
			top=0;
			len=length;
		};		
		T pop();
		T gettop();
		bool empty();
		void clear();
		void push(T);
		int check(){
			return top;
		};
};

long long calculate(char sign,long long a,long long b);

int judge(char sign);

int main()
{	
	zstack<long long> num(1000);
	zstack<char> sign(1000);
	int i,len;
	long long temp=0,a=0,b=0;
	char ch[1000];
	printf("������������Ҫ����ı��ʽ�����Ⱥ�:");
	gets(ch);

	len=strlen(ch);
	
	for(i=0;i<len;i++)
	{
		temp=0;
		if(ch[i]>='0'&&ch[i]<='9')                 //�����ǰλΪ���� 
		{
			temp=ch[i]-'0'+temp*10;
			while(ch[i+1]>='0'&&ch[i+1]<='9')
			{
				temp=ch[i+1]-'0'+temp*10;
				i++;
			}
			num.push(temp);
		}
		
		else if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/')             //�����ǰλΪ������� 
		{
			if(sign.empty())                           //����ַ�ջ�գ���ֱ�ӽ������ѹ��ջ�� 
			    sign.push(ch[i]);
			
			else if(judge(ch[i])>judge(sign.gettop()))   //�����ǰ����������ȼ������ַ�ջ��ջ�������������ѹ�� 
			    sign.push(ch[i]);
			
			else if(judge(ch[i])<=judge(sign.gettop())&&judge(sign.gettop())!=3)   //�����ǰ��������ȼ���ջ������������ȼ��� С��һ�£��򵯳�ջ����������� 
			{
				a=num.pop();
				b=num.pop();
				a=calculate(sign.pop(),b,a);               //Ӧ��ע������˳�� 
				num.push(a);
				sign.push(ch[i]);
			}
			else if(judge(sign.gettop())==3)
			{
				sign.push(ch[i]);
			}
	    }
			
		else if(ch[i]=='(')               //��ǰΪ������ ,ֱ��ѹջ 
			sign.push(ch[i]);
			
		else if(ch[i]==')')              //��ǰΪ������ 
		{
			while(sign.gettop()!='(')
			{
				char str;
				str=sign.pop();
				a=num.pop();
				b=num.pop();
				if(str=='+'&&sign.gettop()=='-')
				{
					b=calculate(sign.pop(),num.pop(),b);
					a=calculate(str,b,a);
					num.push(a);
				}
				
				else
				{
					a=calculate(str,b,a);
					num.push(a);
				}
			}
			sign.pop();               //����'(' 
		}
		
		else if(ch[i]=='=')          //��ǰΪ�Ⱥţ������������� 
		{
			while(!sign.empty())
			{
				a=num.pop();
				b=num.pop();
				a=calculate(sign.pop(),b,a);
				num.push(a);
			}
			long long
			 p=num.pop();
			printf("%lld",p);
		}	
	}	
	return 0;
}


template <typename T>
T zstack<T>::pop()
{
	top--;
	return stack[top];
}

template <typename T>
T zstack<T>::gettop()
{
	return stack[top-1];
}

template <typename T>
void zstack<T>::push(T node)
{
	stack[top]=node;
	top++;
}

template <typename T>
bool zstack<T>::empty()
{
	if(top==0)
		return true;
	else
	    return false;
}

template <typename T>
void zstack<T>::clear()
{
	top=0;
}

long long calculate(char sign,long long a,long long b)
{
	switch(sign)
	{
		case '+':return (a+b); break;
		case '-':return (a-b); break;
		case '*':return (a*b); break;
		case '/':return (a/b);
	}
}

int judge(char sign)
{
	switch(sign)
	{
		case '+':
		case '-':return 1;break;
		case '*':
		case '/':return 2;break;
		case '(':return 3;break;
	}
}
