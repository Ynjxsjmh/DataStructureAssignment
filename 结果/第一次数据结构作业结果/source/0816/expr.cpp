#include<iostream>
#include<cstdio>
using namespace std;
int yunsuan(int a,int b,char c)
{
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
	if(c=='/') return a/b;
}
void s1(char a[200],char b[200],char c[200])
{
	int p=0,q=0;
	for(int i=0;a[i]!='=';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[p++]=a[i];
			if(a[i+1]<'0'||a[i+1]>'9')
			{
				b[p++]='#';
			}
		}
		else if(a[i]==')')
		{
			while(c[--q]!='(')
			{
				b[p++]=c[q];
			}
		}
		else
		{
			if(q>0)
			{
				if(a[i]=='+'||a[i]=='-')
				{
					if(c[q-1]!='(')
					{
						b[p++]=c[--q];
					}
				}
				if(a[i]=='*'||a[i]=='/')
				{
					if(c[q-1]=='*'||c[q-1]=='/')
					{
						b[p++]=c[--q];
					}
				}
			}
			c[q++]=a[i];
		}
	}
	while(q>0)
    {
        b[p++]=c[--q];
    }
	b[p]='\0';
}
void s2(char b[200],int d[50])
{
	int c=0,p=0;
	for(int i=0;b[i]!='\0';i++)
	{
		if(b[i]<='9'&&b[i]>='0')
		{
			c=c*10+(b[i]-'0');
		}
		else if(b[i]=='#')
		{
			d[p++]=c;
			c=0;
		}
		else
		{
			d[p-2]=yunsuan(d[p-2],d[p-1],b[i]);
			p=p-1;
		}
	}
}
int main (){
	char a[200];
	char b[200]={' '};
	char c[200]={' '};
	int d[50];
	FILE*f1,*f2;
	f1=fopen("expr.in","r");
	fscanf(f1,"%s",a);
	//cin>>a;
	s1(a,b,c);
	s2(b,d);
	f2=fopen("expr.out","w");
	fprintf(f2,"%d",d[0]);
	//cout<<d[0]<<endl;
	return 0;
}
