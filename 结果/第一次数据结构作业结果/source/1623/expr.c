#include"stdio.h"
#define N 100
int stack1[N];         //�����������ջ
char stack2[N];        //���������ջ
int top1=-1,top2=-1;
void push1(int x)      //������ѹ���������ջ
{
    stack1[++top1]=x;
}
int pop1()             //�����������ջ�е�ջ��Ԫ��
{
    return stack1[top1--];
}
void push2(char x)    //������ѹ�������ջ
{
    stack2[++top2]=x;
}
char pop2()           //���������ջ�е�ջ��Ԫ��
{
    return stack2[top2--];
}
int cal()            //���������ջ���������ջ��ջ��Ԫ��֮�������
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
    push2('=');       //��ѹ��һ����=��
    scanf("%c",&ch1);
    while(ch1!='=')
    {
        l=0;
        while('0'<=ch1&&ch1<='9')  //�ж�������ַ��Ƿ�Ϊ���ֲ��ж�Ϊ��λ����
         {
          a[l]=ch1-'0';
          ch1=getchar();
          l++;
         }
         if(l==1)  //��������Ϊһλ������ֱ��ѹ��
          push1(a[0]);
         if(l>1)    //���������Ƕ�λ��������ת��Ϊһ������ѹ��
         {
          for(i=0;i<l-1;i++)
         {
             b=a[i]*10+a[i+1];
             a[i+1]=b;
         }
         push1(b);
         }
        if(ch1=='(')        //��Ϊ�����ţ�ֱ��ѹ��
         push2(ch1);
        if(ch1==')')       //��Ϊ�����ţ��������㣬ֱ��ջ��Ԫ��Ϊ�����Ž�����������������
          {
            while(stack2[top2]!='(')
                  cal();
            pop2();

          }
        if(ch1=='+'||ch1=='-') //��Ϊ�Ӽ����㣬ֻҪջ��Ԫ�ز�Ϊ�����Ż�Ⱥţ��ͽ�������
          {
              while(stack2[top2]!='='&&stack2[top2]!='(')
                    cal();
              push2(ch1);
          }
        if(ch1=='*'||ch1=='/')   //��Ϊ�˳����㣬ֻҪջ��Ԫ��Ϊ�˳����ͽ�������
        {
            while(stack2[top2]=='*'||stack2[top2]=='/')
                   cal();
            push2(ch1);
        }
        if(ch1!='=')
         scanf("%c",&ch1);
    }
    while(stack2[top2]!='=')  //�����ջ����ʱ��Ҫ���
      cal();
     printf("%d\n",stack1[top1]); //����������ջ��ջ��Ԫ��
   fclose(stdin);
   fclose(stdout);
   return 0;
}
