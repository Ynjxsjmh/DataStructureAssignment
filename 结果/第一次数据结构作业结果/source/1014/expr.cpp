#include<stdio.h>
#include<stack>
#include<string.h>
#include<string>
using namespace std;
char str[1005];

double calculate(double a,double b,char c)
{
    switch(c)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
int compare(char c)
{
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    if(c=='(') return 0;
    if(c=='=') return -1;
}
int isdigit(char c)   //判断输入是否为数字
{
    if(c>='0' && c<='9')
        return 1;
    return 0;
}
int main()
{
    while(1){
    FILE *fp1,*fp2;
    fp1=fopen("expr.in.txt","r");
    fp2=fopen("expr.out.txt","w");
    while(!feof(fp1))
    {
    fscanf(fp1,"%s",str);
    const int len=strlen(str);   //定义len.
    stack<double> x;    //数字栈
    stack<char> y;      //运算符栈
    y.push('=');        //输入等号结束
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
            x.push(num);
        }
        else if(str[i]=='(')
            y.push(str[i]);
        else if(str[i]==')'){
            while(y.top()!='(')
            {
                double a,b;
                b=x.top(),x.pop();
                a=x.top(),x.pop();
                x.push(calculate(a,b,y.top()));
                y.pop();
            }
            y.pop();}
        else{
            if(compare(y.top())>=compare(str[i]))
            {
                double a,b;
                b=x.top(),x.pop();
                a=x.top(),x.pop();
                x.push(calculate(a,b,y.top()));
                y.pop();
                y.push(str[i]);
            }
            else
                y.push(str[i]);
            }
    }
    if(y.size()==3)
    {
        double a,b;
        b=x.top(),x.pop();
        a=x.top(),x.pop();
        y.pop();
        x.push(calculate(a,b,y.top()));
        y.pop();
    }
    fprintf(fp2,"%.2f\n",x.top());
    x.pop(),y.pop();
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
}
