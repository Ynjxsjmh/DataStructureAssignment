#include<stdio.h>
#include<stdlib.h>
using namespace std;
int ptr=0;

typedef struct Nstack
{
        int top;
        long long num[500];
        Nstack()
        {
                top=-1;
        }
        void push(long long x)
        {
                top++;
                num[top]=x;
        }
        long long pop()
        {
                long long temp=num[top];
                top--;
                return temp;
        }
}nstack;

typedef struct Ostack
{
        int top;
        char opt[500];
        Ostack()
        {
                top=-1;
        }
        void push(char x)
        {
                top++;
                opt[top]=x;
        }
        char pop()
        {
                char temp=opt[top];
                top--;
                return temp;
        }
        char peek()
        {
                return opt[top];
        }
        int emp()
        {
                return top==-1;
        }
}ostack;

long long change(char str[])
{
        long long n=0;
        for(;(str[ptr]<='9'&&str[ptr]>='0');ptr++)
        {
                n=n*10+(str[ptr]-'0');
        }
        ptr--;
        return n;
}

long long act(long long n1,char opt,long long n2)
{
        switch(opt)
        {
                case '+': return n1+n2;
                case '-': return n1-n2;
                case '*': return n1*n2;
                case '/': return n1/n2;
        }
}

int main()
{
        nstack nst; ostack ost; char str[1000]; int size;
        /*for(size=0;(str[size-1]!='=');size++)
                scanf("%c",&str[size]);*/
        FILE *inp,*outp;
        if((inp=fopen("expr.in","r"))==NULL)
	{
		//printf("文件打开失败！");
		exit(0);
	}
	if((outp=fopen("expr.out","w"))==NULL)
	{
		//printf("文件创建失败！");
		exit(0);
	}
	for(size=0;(str[size-1]!='=');size++)
                fscanf(inp,"%c",&str[size]);
        for(ptr;ptr<size-1;ptr++)
        {
                if(str[ptr]<='9'&&str[ptr]>='0')
                {
                        nst.push(change(str));
                        if(ost.peek()=='*'||ost.peek()=='/')
                                nst.push(act(nst.pop(),ost.pop(),nst.pop()));
                }
                else
                {
                        ost.push(str[ptr]);
                        if(str[ptr]==')')
                        {
                                ost.pop();
                                while(ost.peek()!='(')
                                {
                                        nst.push(act(nst.pop(),ost.pop(),nst.pop()));
                                }
                                ost.pop();
                                while(ost.peek()=='*'||ost.peek()=='/')
                                        nst.push(act(nst.pop(),ost.pop(),nst.pop()));
                        }
                }
        }
        while(!ost.emp())
        {
                nst.push(act(nst.pop(),ost.pop(),nst.pop()));
        }
        fprintf(outp,"%d",nst.pop());
        fclose(inp);
        fclose(outp);
	//printf("END");
        return 0;
}
