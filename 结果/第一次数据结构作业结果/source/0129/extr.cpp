#include <string.h>
#include <iostream>
using namespace std;

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
};

int calculate(char,int,int);

int main()
{

	freopen("test.txt","r",stdin);
	freopen("test.out","w",stdout);
	
	zstack<int> num(1000);
	zstack<char> sign(1000);
	int i,k,len;
	int temp,temp1;
	char ch[1000];
	scanf(" %s",ch);
		
	len=strlen(ch);
		
	temp=0;

	for(i=0;i<len;i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')
			temp=ch[i]-'0'+temp*10;		
			
		else if(ch[i]=='(')			    
			sign.push(ch[i]);
			
		else if(ch[i]==')')
		{
			while(sign.gettop()!='(')			
			   	temp=calculate(sign.pop(),num.pop(),temp);				
			sign.pop();
		}
				
		else                          //此种情况为ch[i]为运算符号的情况     
		{                                
			if(sign.empty())
			    sign.push(ch[i]);      
			else
			{
			    if(sign.gettop()=='*'||sign.gettop()=='/'||((sign.gettop()=='+'||sign.gettop()=='-')&&(ch[i]=='+'||ch[i]=='-')))     //判断运算符的优先级，判断是否能算
			    	temp=calculate(sign.pop(),num.pop(),temp);
			    sign.push(ch[i]);			    		
			}
			num.push(temp);
			temp=0;
		}	    
	}
	while(!sign.empty())		
		temp=calculate(sign.pop(),num.pop(),temp); 
			
	printf("%d\n",temp);
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

int calculate(char sign,int a,int b)
{
	switch(sign)
	{
		case '+':return (a+b); break;
		case '-':return (a-b); break;
		case '*':return (a*b); break;
		case '/':return (a/b);
	}
}
