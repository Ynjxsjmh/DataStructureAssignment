#include"stdio.h"
#define N 100
int stack1[N];         //声明运算分量栈
char stack2[N];        //声明运算符栈
int top1=-1,top2=-1;
void push1(int x)      //将变量压入运算分量栈
{
    stack1[++top1]=x;
}
int pop1()             //弹出运算分量栈中的栈顶元素
{
    return stack1[top1--];
}
void push2(char x)    //将变量压入运算符栈
{
    stack2[++top2]=x;
}
char pop2()           //弹出运算符栈中的栈顶元素
{
    return stack2[top2--];
}
int cal()            //进行运算符栈和运算分量栈的栈顶元素之间的运算
{
    int a1,a2,a;
	int i;
    char ch;
    ch=pop2();
    a1=pop1();
    a2=pop1();
    if(ch=='+')
     a=a1+a2;
    if(ch=='-')
     a=a2-a1;
    if(ch=='*')
     a=a1*a2;
    if(ch=='/')
     a=a2/a1;
     push1(a);
     return a;
}
int main()
{
    int a[N];
    int l,i;
    int b;
    char ch1;
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    push2('=');       //先压入一个‘=’
    scanf("%c",&ch1);
    while(ch1!='=')
    {
        l=0;
        while('0'<=ch1&&ch1<='9')  //判断输入的字符是否为数字并判断为几位数字
         {
          a[l]=ch1-'0';
          ch1=getchar();
          l++;
         }
         if(l==1)  //如果输入的为一位数，则直接压入
          push1(a[0]);
         if(l>1)    //如果输入的是多位数，将其转化为一个整数压入
         {
          for(i=0;i<l-1;i++)
         {
             b=a[i]*10+a[i+1];
             a[i+1]=b;
         }
         push1(b);
         }
        if(ch1=='(')        //若为左括号，直接压入
         push2(ch1);
        if(ch1==')')       //若为右括号，进行运算，直到栈顶元素为左括号结束，并弹出左括号
          {
            while(stack2[top2]!='(')
                  cal();
            pop2();

          }
        if(ch1=='+'||ch1=='-') //若为加减运算，只要栈顶元素不为左括号或等号，就进行运算
          {
              while(stack2[top2]!='='&&stack2[top2]!='(')
                    cal();
              push2(ch1);
          }
        if(ch1=='*'||ch1=='/')   //若为乘除运算，只要栈顶元素为乘除，就进行运算
        {
            while(stack2[top2]=='*'||stack2[top2]=='/')
                   cal();
            push2(ch1);
        }
        if(ch1!='=')
         scanf("%c",&ch1);
    }
    while(stack2[top2]!='=')  //运算符栈不满时，要清空
      cal();
     printf("%d\n",stack1[top1]); //输出运算分量栈的栈顶元素
   fclose(stdin);
   fclose(stdout);
   return 0;
}
