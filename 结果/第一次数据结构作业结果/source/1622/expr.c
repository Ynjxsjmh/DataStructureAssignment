#include <stdio.h>
char sym[1000],sym_top=-1;
int num[1000],num_top=-1,number[20],i=0,j;
int num_pop()   //����ջ����
{
    return(num[num_top--]);
}
char sym_pop()  //�����ջ����
{
    return(sym[sym_top--]);
}
void num_push(int a)   //����ջѹ��
{
    num[++num_top]=a;
}
void sym_push(char a)   //�����ջ����
{
    sym[++sym_top]=a;
}
void arith()  //�������㺯��
{
    int u,v;
    char m;
    u=num_pop();
    v=num_pop();
    m=sym_pop();
    switch(m)
    {
        case '+':v=v+u;break;
        case '-':v=v-u;break;
        case '*':v=v*u;break;
        case '/':v=v/u;break;
    }
    num_push(v);
}

int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out.","w",stdout);
    sym_push('@');
    char ch;
    ch=getchar();
    while(ch!='=')
    {
        if(ch<='9'&&ch>='0'){           //������������
             while(ch<='9'&&ch>='0'){
                 number[i++]=(ch-'0');
                 ch=getchar();
            }
            for(j=0;j<i-1;j++)
            {
                number[j+1]=number[j]*10+number[j+1];
            }
            num_push(number[i-1]);
            i=0;
        }
        else                     //���������
        {
            switch(ch)
            {
                case '(':sym_push(ch);break;
                case ')':{
                           while(sym[sym_top]!='(')
                          {
                              arith();
                            }
                           sym_pop();
                           break;
                          }
                case '+':{
                           while(sym[sym_top]=='-'||sym[sym_top]=='+'||sym[sym_top]=='*'||sym[sym_top]=='/')
                          {
                              arith();
                            }
                           sym_push(ch);
                           break;
                          }
                case '-':{
                           while(sym[sym_top]=='-'||sym[sym_top]=='+'||sym[sym_top]=='*'||sym[sym_top]=='/')
                          {
                              arith();
                            }
                           sym_push(ch);
                           break;
                          }
                case '*':{
                           while(sym[sym_top]=='*'||sym[sym_top]=='/')
                          {
                              arith();
                            }
                           sym_push(ch);
                           break;
                          }
                case '/': {while(sym[sym_top]=='*'||sym[sym_top]=='/')
                          {
                              arith();
                            }
                           sym_push(ch);
                           break;
                         }
            }
              ch=getchar();
        }
    }
    while(sym_top!=0)
    {
         arith();
    }
    printf("%d\n",num[num_top]);
   fclose(stdin);
   fclose(stdout);
    return 0;
}
