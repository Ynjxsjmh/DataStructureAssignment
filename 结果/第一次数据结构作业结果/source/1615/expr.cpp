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
    if(x==0)   { cout<<"���ʽ����"<<endl; }
    if(ch=='/')  return y/x;
}

void  pushb(ll t,char ch,int i)
{
    if(i==b.size())                  { b.push(ch); return; } //ѹ��ǰ�����ţ�
    if(isdigit(st[i-1])&&flag==0)    { a.push(t); flag=1;}   //ѹ�����֣�

    if(b.empty())  b.push(ch);                //��һ���������
    else if(p[ch]< p[b.top()] ) b.push(ch);   //���ȼ�С��ֱ��ѹ��
    else                                      //���ȼ��󣬼������ѹ�룻
    {
        if(b.top()=='('&&ch==')') b.pop();    //���Ų�����
        else if(b.top()=='(')  b.push(ch);    //���Ų�����

        else  // ����Ӽ��˳���
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
    for(int i=0; st[i]!='\0'; i++) //���ַ��������
    {
        ll t;//���浱ǰ����
        char ch=st[i];
        if(isdigit(ch))  //ת�������浱ǰ���֣�
        {
            if(i==0)   t=ch-'0';
            else if(!isdigit(st[i-1])) t=ch-'0';
            else                  t=10*t + ch-'0';
        }
        else //�����������
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
    /* ���ȼ��趨 */
    p['(']=1; p['*']=2; p['/']=2; p['+']=3; p['-']=3;p[')']=4;p['=']=5;

    scanf("%s",st);
    /*��� ����ջ �� ����ջ */
    while(!a.empty())
    a.pop();
    while(!b.empty())
    b.pop();
    solve();//������ʽ����������
    fclose(stdin);
    fclose(stdout);
    return 0;
}
