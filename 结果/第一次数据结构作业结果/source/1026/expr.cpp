#include<stack>
#include<cstring>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
char str[100];
int cmp(char y)
{
    if(y=='-'||y=='+') return 1;
    if(y=='*'||y=='/') return 2;
    if(y=='(') return 0;
    if(y=='=') return -1;
}
int isdigit(char x)
{
    if(x>='0'&&x<='9')
        return 1;
    return 0;
}
double cal(double x,double y,char z)
{
    switch(z)
    {
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
    }
}
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("expr.in","r");
    fp2=fopen("expr.out","w");
    while(!feof(fp1)){
    fscanf(fp1,"%s",str);
    const int len=strlen(str);
    stack<double> a;
    stack<char> b;
    b.push('=');
    for(int i=0;i<len;i++)
    {
        if(isdigit(str[i]))
        {
            double num=str[i]-'0';
            while(isdigit(str[i+1]))
            {
                num=num*10+str[i+1]-'0';
                i++;
            }
            a.push(num);
        }
        else if(str[i]=='(')
            b.push(str[i]);
        else if(str[i]==')'){
            while(b.top()!='(')
            {
                double x,y;
                y=a.top(),a.pop();
                x=a.top(),a.pop();
                a.push(cal(x,y,b.top()));
                b.pop();
            }
            b.pop();}
        else{
            if(cmp(b.top())>=cmp(str[i]))
            {
                double x,y;
                y=a.top(),a.pop();
                x=a.top(),a.pop();
                a.push(cal(x,y,b.top()));
                b.pop();
                b.push(str[i]);
            }
            else
                b.push(str[i]);
            }
    }
    if(b.size()==3)
    {
        double x,y;
        y=a.top(),a.pop();
        x=a.top(),a.pop();
        b.pop();
        a.push(cal(x,y,b.top()));
        b.pop();
    }
    fprintf(fp2,"%.f\n",a.top());
    a.pop(),b.pop();}
    //printf("计算结束，结果已存入文件\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}
