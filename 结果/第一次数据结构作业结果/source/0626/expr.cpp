//×îºóĞŞ¸Ä 20170410 22£º30 
#include<iostream>
#include<stack>
int oper(char c,int a,int b)
{
	switch(c)
	{
	   case '+':return a+b;
	   case '-':return a-b;
	   case '*':return a*b;
	   case '/':return a/b;	
	}
}
using namespace std;
int main()
{
	stack<char> A,A1;
	stack<int> B,B1;
    FILE*inputfile,*outputfile;
	int a,b,temp,k,j;
    char i;
    char*now;
    char str[1001],str1[256],str2[256];
    
    if((inputfile=fopen("expr.in","r"))==NULL)
    {
    	printf("can't open the sourse file:\n");
    	exit(0);
	}
	if((outputfile=fopen("expt.out","w"))==NULL)
    {
    	printf("can't open the destination file:\n");
        exit(0);
	}
	while(!feof(inputfile))
	{
	fscanf(inputfile,"%s",str);
	a=b=temp=k=0;
    now=str;
    while(*now!='=')
    {
    	if(*now=='(')
    	{
    		A.push(*now);
		}
		else if(*now>='0'&&*now<='9')
		{
			temp=*now-48;
			while(*(now+1)>='0'&&*(now+1)<='9')
			{
				now++;
				temp=temp*10+*now-48;
			}
			B.push(temp);
		}
		else if(*now=='*'||*now=='/' )
		{
			if(!A.empty())
			{
				if(A.top()=='*'||A.top()=='/')
				{
					a=B.top(),B.pop(),b=B.top(),B.pop();
					k=oper(A.top(),b,a);
					B.push(k);
					A.pop();
				}
			}
			A.push(*now);
		}
		else if(*now=='+'||*now=='-')
		{
			if(!A.empty())
			{
				if(A.top()=='*'||A.top()=='/'||A.top()=='+'||A.top()=='-')
				{
					a=B.top(),B.pop(),b=B.top(),B.pop();
					k=oper(A.top(),b,a);
					B.push(k);
					A.pop();
				}
			}
			A.push(*now);
		}
		else if(*now==')')
		{
			while(1)
			{
				a=B.top(),B.pop(),b=B.top(),B.pop();
				k=oper(A.top(),b,a);
				A.pop();
				B.push(k);
				if(A.top()=='(')
				{
					A.pop();
					break;
				}
			}
		}
		if(*(now+1)=='=')
		{
			if(!A.empty())
			{
				if(A.top()=='*'||A.top()=='/')
				{
					a=B.top(),B.pop(),b=B.top(),B.pop();
					k=oper(A.top(),b,a);
					B.push(k);
					A.pop();
				}
			}
			while(!A.empty())
			{
				A1.push(A.top());
				A.pop();
			}
			while(!B.empty())
			{
				B1.push(B.top());
				B.pop();
			}
			while(!A1.empty())
			{
				a=B1.top(),B1.pop(),b=B1.top(),B1.pop();
				k=oper(A1.top(),a,b);
				B1.push(k);
				A1.pop();
			}
		}
		now++;
		
	}
	  fprintf(outputfile,"%s%d\n",str,k);
	}
    
} 
