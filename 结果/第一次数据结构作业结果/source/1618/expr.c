#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s1[1001]; //输入的表达式所存放的栈
char s2[1001]; //运算数栈
int j=0; //指向s2字符串的指针
struct node //定义结构体。(运算符栈)
{
    char data;
    int num;
    struct node *next;
};
struct node *Initialization()//初始化栈链,链栈不带头结点，此栈用来存放运算符的栈
{
    struct node *top;
    top=(struct node *)malloc(sizeof(struct node));
    top->data=';';
    top->num=0;
    top->next=NULL;
    return top;
}
struct node *assort(struct node *s)//将输入表达式分堆
{
    struct node *p,*top;
    int i;//指向s1字符串当前的指针
    top=s;
    int m;
    char a;
    m=strlen(s1);
    for(i=0; i<m-1; i++)
    {
        a=s1[i];
        if('0'<=s1[i]&&s1[i]<='9')
        {
            s2[j]=s1[i];
            j++;
        }
        else
        {
            switch(a)
            {
                case '(':
                {
                    p=(struct node *)malloc(sizeof(struct node));
                    p->data=a;
                    p->next=top;
                    top=p;
                    break;
                }
                case '*':
                case '/':
                s2[j]=' ';
                j++;
                if((top->data=='*')||(top->data=='/'))
                {
                    s2[j]=top->data;
                    j++;
                    top->data=a;
                    break;
                }
                else
                {
                    p=(struct node *)malloc(sizeof(struct node));
                    p->data=a;
                    p->next=top;
                    top=p;
                    break;
                }
                case '+':
                case '-':
                {
                    s2[j]=' ';
                    j++;
                    if(top->data=='+'||top->data=='-'||top->data=='*'||top->data=='/')
                    {
                        s2[j]=top->data;
                        j++;
                        top->data=a;
                        break;
                    }
                    else
                    {
                        p=(struct node *)malloc(sizeof(struct node));
                        p->data=a;
                        p->next=top;
                        top=p;
                        break;
                    }
                }
                case ')':
                {
                    s2[j]=' ';
                    j++;
     while(top->data!='(')
        {
            s2[j]=top->data;
            j++;
            p=top;
            top=top->next;
            free(p);
        }
        p=top;
        top=top->next;
        free(p);
        break;
        }
    }
}
}
while(top->data!=';')
{
    s2[j]=top->data;
    j++;
    p=top;
    top=top->next;
    free(p);
}
s2[j]=';';
printf("后缀表达式为:");
for(i=0; i<j; i++)
    if(s2[i]!=' ')
    printf("%c ",s2[i]);
printf("\n");
return top;
}
int calculate(struct node *s)
//计算表达式的值
{
struct node *top,*p;
char *q;
int x,y,a;int i,n;
top=s;//指向栈顶的指针
for(i=0; i<=j; i++) //遍历字符串s2
{
    if(s2[i]>='0'&&s2[i]<='9')
    {
        q=&s2[i];
        a=atoi(q);
    for(n=i; s2[n]>='0'&&s2[n]<='9'; n++) {}
    p=(struct node *)malloc(sizeof(struct node ));
    p->num=a;
    p->next=top;
    top=p;
    i=n-1;
}
else if(s2[i]==';') //遇；号结束标志，输出栈中的最后计算结果
        return top->num;
    else
    {
        if(s2[i]==' ') {}
    else
    {
        y=top->num;
        p=top;
        top=top->next;
        free(p);
        x=top->num;
        p=top;
        top=top->next;
        free(p);
        switch(s2[i])
        {
            case '+':
            {
                a=x+y;
                p=(struct node *)malloc(sizeof(struct node));
                p->num=a;
                p->next=top;
                top=p;
                break;
            }
            case '-':
            {
            a=x-y;
            p=(struct node *)malloc(sizeof(struct node ));
            p->num=a;
            p->next=top;
            top=p;
            break;
        }
            case '*':
            {
                a=x*y;
                p=(struct node *)malloc(sizeof(struct node ));
                p->num=a;
                p->next=top;
                top=p;
                break;
            }
            case '/':
            {
                a=(float)x/y;
                p=(struct node *)malloc(sizeof(struct node ));
                p->num=a;
                p->next=top;
                top=p;
                break;
            }
        }
    }
}
}
}
/*主函数*/
 int main()
{
struct node *top,*head;
top=Initialization();
printf("请输入表达式（运算符号可以为：+、-、*、/、(、)）：\n");
gets(s1);
FILE*f1;//输入文件
FILE*f2;//输出文件
if((f1=fopen("expr.in.txt","w"))==NULL)//打开输入文件
{
    printf("输入文件打开失败\n");
    return 0;
}
if((f2=fopen("expr.out.txt","w"))==NULL)//打开输出文件
{
    printf("输出文件打开失败\n");
    return 0;
}
int i=0;
while(s1[i]!=0)
{
    fprintf(f1,"%c",s1[i]);
    i++;
}
head=assort(top);
int result=calculate(head);
fprintf(f2,"%d",result);
printf("%d",result);
fclose(f2);
fclose(f1);
return 0;
}
