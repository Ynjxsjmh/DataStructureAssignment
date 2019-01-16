#include <bits/stdc++.h>
using namespace std;
#define maxn 2000
struct node
{
    int n,f;
}a[maxn];
int len;
char st;
void read()
{
    a[0].f=1;
    while(1)
    {
        st=getchar();

        if(st>='0'&&st<='9')
        {
            if(a[len].f)
            {
                len++;
                a[len].n=st-'0';
            }
            else
            {
                a[len].n=a[len].n*10+st-'0';
            }
        }
        else
        {
            len++;a[len].f=1;a[len].n=st;
        }
        if(st=='=')
        {
            break;
        }
    }
}
int pri(int x)
{
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='('||x==')') return 0;
}
stack<int>s1,s2;
int get(int a,int b,int c)
{
    if(c=='+') return a+b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
    if(c=='/') return a/b;
}
void cal()
{
    int n1=s1.top();
    s1.pop();
    int n2=s1.top();
    s1.pop();
    int op=s2.top();
    s2.pop();
    int tmp;
    tmp=get(n2,n1,op);
    s1.push(tmp);
}
void print(int i)
{
        stack<int>c1,c2;
        printf("step %d:\n",i);
        if(a[i].f) printf("%c\n",a[i].n);
        else printf("%d\n",a[i].n);
        printf("///////////////////////////////");
        printf("\n");
        c2=s1;
        while(!c2.empty()) c1.push(c2.top()),c2.pop();
        while(!c1.empty()) printf("%d ",c1.top()),c1.pop();
        printf("\n");
        c2=s2;
        while(!c2.empty()) c1.push(c2.top()),c2.pop();
        while(!c1.empty()) printf("%c ",c1.top()),c1.pop();
        printf("\n");
        printf("////////////////////////////////////////////////////////");
        system("pause");
}
int solve()
{

    for(int i=1;i<=len;i++)
    {

        if(!a[i].f)
        {
            s1.push(a[i].n);
        }
        else
        {
            if(a[i].n=='=')
            {
                while(!s2.empty())
                {
                    cal();
                }
                return s1.top();

            }
            else if(a[i].n=='(')
            {
                s2.push(a[i].n);

            }
            else if(a[i].n==')')
            {
                while(s2.top()!='(') cal();
                s2.pop();
            }

            else if(s2.empty()|| pri(a[i].n)>pri(s2.top()) )
            {
                s2.push(a[i].n);
            }
            else
            {
                while(!s2.empty()&&pri(a[i].n)<=pri(s2.top())) cal();
                s2.push(a[i].n);
            }
        }
        //print(i);

    }
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    read();
    printf("%d\n",solve());
    return 0;
}
/*
74/35*7*295+4-7*5/50/623-83+(8*44+813*16*55)/650+7-5-(6)/843/(37+256/920)=
1+0/100/200/200=
74/35*7*295=4130
4-7*5/50/623-83=-79
(8*44+813*16*55)/650=
7-5-(6)/843/(37+256/920)=
*/
