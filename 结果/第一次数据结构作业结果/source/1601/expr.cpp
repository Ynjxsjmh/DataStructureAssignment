#include<stdio.h>

char stackArray1[1001];
int stackArray2[1001];
int top1=-1;
int top2=-1;

void push_char(char x)
{
	stackArray1[++top1]=x;
}

char pop_char(void)
{
	if(top1==-1)
	{
		return '\0';	
	}
	else return stackArray1[top1--];
}

char peek_char(void)
{
	if(top1==-1)
	{
		return '\0';	
	}
	return stackArray1[top1];
}

void push_num(int x)
{
	stackArray2[++top2]=x;
}

int pop_num(void)
{
	if(top2==-1)
	{
		return 0;	
	}
	else return stackArray2[top2--];
}

int peek_num(void)
{
	if(top2==-1)
	{
		return '\0';	
	}
	return stackArray2[top2];
}

int oper(void)
{
	int v1, v2, v;
	char op;
	op=pop_char();
	v2=pop_num();
	v1=pop_num();
	switch(op)
	{
		case'+':v=v1+v2;break;
		case'-':v=v1-v2;break;
		case'*':v=v1*v2;break;
		case'/':v=v1/v2;break;
	}
	push_num(v);
	return v;
}


int main() 
{
	FILE *in, *out;
	in=fopen("expr.in", "a+");
	fprintf(in, "\n");
	fclose(in);
	in=fopen("expr.in", "r");
	out=fopen("expr.out", "w");
	while(!feof(in))
	{
		int i = 0;
		char str[1001], ch;
		top1=-1;
		top2=-1;
		fgets(str, 1001, in);
		ch=str[i];
		while(ch!='\0')
		{
			if(ch>='0'&&ch<='9')
			{
				int n=ch-'0';
				ch=str[++i];
				while(ch>='0'&&ch<='9')
				{
					n=n*10+ch-'0';
					ch=str[++i];
				}
				push_num(n);
				i--;
			} 
			else switch(ch)
			{
				case'(':push_char(ch);break;
				case')':while(peek_char()!='(')
						oper();
						pop_char();
						break;
				case'+':while(peek_char()!='('&&top1!=-1)
						oper();
						push_char(ch);
						break;
				case'-':while(peek_char()!='('&&top1!=-1)
						oper();
						push_char(ch);
						break;
				case'*':while(peek_char()=='*'||peek_char()=='/')
						oper();
						push_char(ch);
						break;
				case'/':while(peek_char()=='*'||peek_char()=='/')
						oper();
						push_char(ch);
						break;
				case' ':break;
				case'\n':break;
				case'=':while(top1!=-1&&top2!=-1)
						oper();
					        fprintf(out, "%d\n", peek_num());
						break;
			}
			ch=str[++i];
		}
	} 
	return 0;
}
