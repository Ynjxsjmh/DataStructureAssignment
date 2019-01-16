#include <iostream>
#include <cstdio>
#include <cctype>
#include <stack>
#include <map>
#define ll long long
using namespace std;
stack <ll> a;
stack <char> b;
map <char, int> p;
char  st[1010];  int flag;

int cal(int x, int y, char ch)
{
    if(ch=='+')  return x+y;
    if(ch=='-')  return y-x;
    if(ch=='*')  return x*y;
    if(x==0)   { cout<<"表达式错误"<<endl; }
    if(ch=='/')  return y/x;
}

void  pushb(ll t,char ch,int i)
{
    if(i==b.size())                  { b.push(ch); return; } //压入前导括号；
    if(isdigit(st[i-1])&&flag==0)    { a.push(t); flag=1;}   //压入数字；

    if(b.empty())  b.push(ch);                //第一个运算符；
    else if(p[ch]< p[b.top()] ) b.push(ch);   //优先级小，直接压入
    else                                      //优先级大，计算后再压入；
    {
        if(b.top()=='('&&ch==')') b.pop();    //括号不运算
        else if(b.top()=='(')  b.push(ch);    //括号不运算

        else  // 计算加减乘除；
        {
            ll x=a.top(); a.pop();
            ll y=a.top(); a.pop();
            a.push(cal(x,y,b.top()));
            b.pop();
            pushb(t,ch,i);
        }
    }
}

void solve()
{
    for(int i=0; st[i]!='\0'; i++) //对字符逐个处理；
    {
        ll t;//保存当前数字
        char ch=st[i];
        if(isdigit(ch))  //转化并保存当前数字；
        {
            if(i==0)   t=ch-'0';
            else if(!isdigit(st[i-1])) t=ch-'0';
            else                  t=10*t + ch-'0';
        }
        else //遇到运算符号
        {
            flag = 0;
            pushb(t,ch,i);
        }
    }
    printf("%d\n",a.top());
}



int main()
{
    freopen("expr.in", "r" ,stdin );
    freopen("expr.out", "w" , stdout);
    /* 优先级设定 */
    p['(']=1; p['*']=2; p['/']=2; p['+']=3; p['-']=3;p[')']=4;p['=']=5;

    scanf("%s",st);
    /*清空 数字栈 和 符号栈 */
    while(!a.empty())
    a.pop();
    while(!b.empty())
    b.pop();
    solve();//计算表达式并输出结果；
    fclose(stdin);
    fclose(stdout);
    return 0;
}
