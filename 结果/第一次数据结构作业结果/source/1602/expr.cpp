#include<stdio.h>
#define key 0
struct sign2
{
    char c[100];
    int top;
    sign2(){top = 0; c[0] = '+';}
    void pushh(char b){c[++top] = b;}
    char popp(void){return c[top--];}
    char peek(void){return c[top];}
};
template <class T>
struct sign1
{
    T c[100];
    T top;
    sign1(){top = -1;}
    void pushh(int b){c[++top] = b;}
    T popp(void){return c[top--];}
    T peek(void){return c[top];}
};
sign1<int> n;
sign1<char> f;
void cul(void)
{
    if(n.top <= 0 || f.peek() == '(')return;
    //if(key)printf("\n##%d\n", n.top);
    int a, b, c;
    char s;
    b = n.popp();
    a = n.popp();
    s = f.popp();
    if(key) printf("\n#####  s:%c a:%d  b:%d ",f.peek(), a, b);
    switch(s)
    {
        case '+': c = a + b;if(f.peek() == '-')c = 0 - c;break;
        case '-': c = a - b;if(f.peek() == '-')c = 0 - c;break;
        case '*': c = a * b;break;
        case '/': c = a / b;break;
        case '%': c = a % b;break;
        case '^': c = a ^ b;break;
    }
    if(key)printf("\n$@$@$ %d %d  %c  %d = %d\n", n.top, a, s, b, c);
    n.pushh(c);
}
char a[1000];
int main(void)
{
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    f.c[0] = '+';
    f.top = 0;
    char s, b = '*';
    scanf("%s", a);
    if(key)printf("%s\n", a);
   // printf("%c\n",a[0]);
   // printf("%s\n", a);
    int i = 0;
    s = a[i];
    while(s != '=')
    {
       // if(key)printf("\ns:%c\n", s);
        if(f.top >= 0)b = f.peek();
       // if(key)printf("\n@ b:%c\n",b);
        switch(s)
        {

            case '+': while(n.top > 0 && f.peek() != '(')cul(); f.pushh(s); break;
            case '-': while(n.top > 0 && f.peek() != '(')cul(); f.pushh(s); break;
            //感觉这两个是错误的，考虑 栈里面有东西，那么无论如何 + — 都不能入栈，
            //因为入栈的条件是当前操作符的优先级大于栈顶符号，所以 + - 不能直接入栈
            case '*': if(b != '+' && b != '-')cul(); f.pushh(s); break;
            case '/': if(b != '+' && b != '-')cul(); f.pushh(s); break;
            case '^': f.pushh(s); break;
            case '%': if(b == '^')cul(); f.pushh(s); break;
            case '(': f.pushh(s); break;
            case ')': while(f.peek() != '(') cul(); f.popp();break;
        }
        if(s <= '9' && s >= '0')
        {
            int x = s - '0';
            while(a[++i] <= '9' && a[i] >= '0')
                x = x * 10 + (a[i] - '0');
         //   if(key)printf(" ## %d $ ", x);
            n.pushh(x);
            s = a[i];
        }
        else s = a[++i];
      //  if(key)printf("%c", s);
    }
    while(n.top > 0)
    cul();
    printf("%d", n.popp());
    return 0;
}
