#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<stack>
using namespace std;
FILE *input;
FILE *output;
stack<int> s;//后缀表达式的计算
stack<char> p;
char m[5000];//存中缀表达式
int d,number,i,j;
bool priority(char b){
switch(b){
case '+':if(p.empty()) return true;
else  if(p.top()=='*'||p.top()=='/')
return false;
else return true;
case '-':if(p.empty()) return true;
else  if(p.top()=='*'||p.top()=='/')
return false;
else
return true;
case '(':return true;
case')':return false;
case '*': return true;
case'/':return true;}
}
int calculate(char b){
    int e=s.top();
    s.pop();
    int f=s.top();
    s.pop();
    switch(b){
case'+':return (e+f);
case'-':return (f-e);
case'*':return (e*f);
case'/':return (f/e);
    }
}
int f1(){
for(i=0;m[i]!='=';)
{
    if(m[i]>='0'&&m[i]<='9')
    {j=10;
    number=0;
    while(m[i]>='0'&&m[i]<='9')
    {number=j*number+m[i]-'0';
    i++;
    }
s.push(number);
    }
else
{if(priority(m[i]))
{p.push(m[i]);
i++;}
else if(m[i]!=')')
{
   d=calculate(p.top());
   s.push(d);
    p.pop();
     p.push(m[i]);
    i++;

}
else {while(p.top()!='(')
{
    d=calculate(p.top());
    s.push(d);
    p.pop();
}
p.pop();
i++;
}
}
}
while(!p.empty())
{d=calculate(p.top());
s.push(d);
    p.pop();
}
return d;
}

int main(){
    int z;
if((input=fopen("expr.in.txt","r"))==NULL)
    printf("can not open the flie");
fscanf(input,"%s",m);
z=f1();
if((output=fopen("expr.out.txt","w"))==NULL)
    printf("can not open the flie");
fprintf(output,"%d",z);//d为最终结果变量
fclose(input);
fclose(output);
return 0;
   }
