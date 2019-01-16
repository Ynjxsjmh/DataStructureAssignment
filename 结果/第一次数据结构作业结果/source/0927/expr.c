#include<stdio.h>
#include <math.h>
int j=-1,k=-1;
long long a[100]={0},b[100]={0};
void calcu(){
switch(b[k--])///////////////
{
case -1:break;//a[j]=a[j-1];j--;
case -2:a[j-1]=a[j-1]+a[j];j--;break;
case -3:a[j-1]=a[j-1]-a[j];j--;break;
case -4:a[j-1]=a[j-1]*a[j];j--;break;
case -5:a[j-1]=a[j-1]/a[j];j--;break;
};
}
int main()
{   FILE *fpin,*fpout;
    fpin=freopen("expr.in","r",stdin);
    fpout=freopen("expr.out","w",stdout);//in与out文件真的可以被识别吗？
    long long num=0;
    int ch=0,f=0;
    while(ch!=-8)
    {
        ch=getchar();
        if(ch>='0'&&ch<='9')
            {num=num*10+ch-'0';f=1;continue;}
        else
            switch (ch){
        case '(':ch=-1;break;
        case '+':ch=-2;break;
        case '-':ch=-3;break;
        case '*':ch=-4;break;
        case '/':ch=-5;break;
        case ')':ch=-7;break;
        case '=':ch=-8;break;
        };
        ///数据读入与处理部分////////////////////////
    if(f)
    {a[++j]=num;
    num=0;
    f=0;}
    if(ch==-1)
        b[++k]=ch;
    else if(k==-1||(ch>=-5&&ch/2<b[k]/2))
        b[++k]=ch;
    else if(ch>=-5)
        {calcu();
        b[++k]=ch;}
    else if(ch==-7)
    {
    while(b[k]!=-1)
    calcu();
    calcu();///不同1
    }
    else if(ch==-8)
    while(k>=0)
    calcu();
    else printf("error");
    }
    printf("%d",a[j]);
    return 0;
}
