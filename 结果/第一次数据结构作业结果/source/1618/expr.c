#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s1[1001]; //����ı��ʽ����ŵ�ջ
char s2[1001]; //������ջ
int j=0; //ָ��s2�ַ�����ָ��
struct node //����ṹ�塣(�����ջ)
{
    char data;
    int num;
    struct node *next;
};
struct node *Initialization()//��ʼ��ջ��,��ջ����ͷ��㣬��ջ��������������ջ
{
    struct node *top;
    top=(struct node *)malloc(sizeof(struct node));
    top->data=';';
    top->num=0;
    top->next=NULL;
    return top;
}
struct node *assort(struct node *s)//��������ʽ�ֶ�
{
    struct node *p,*top;
    int i;//ָ��s1�ַ�����ǰ��ָ��
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
printf("��׺���ʽΪ:");
for(i=0; i<j; i++)
    if(s2[i]!=' ')
    printf("%c ",s2[i]);
printf("\n");
return top;
}
int calculate(struct node *s)
//������ʽ��ֵ
{
struct node *top,*p;
char *q;
int x,y,a;int i,n;
top=s;//ָ��ջ����ָ��
for(i=0; i<=j; i++) //�����ַ���s2
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
else if(s2[i]==';') //�����Ž�����־�����ջ�е���������
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
/*������*/
 int main()
{
struct node *top,*head;
top=Initialization();
printf("��������ʽ��������ſ���Ϊ��+��-��*��/��(��)����\n");
gets(s1);
FILE*f1;//�����ļ�
FILE*f2;//����ļ�
if((f1=fopen("expr.in.txt","w"))==NULL)//�������ļ�
{
    printf("�����ļ���ʧ��\n");
    return 0;
}
if((f2=fopen("expr.out.txt","w"))==NULL)//������ļ�
{
    printf("����ļ���ʧ��\n");
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
