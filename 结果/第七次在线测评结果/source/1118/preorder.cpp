#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
char a[50]={0};
char b[50]={0};
void print(int starta,int enda,int bpos)
{
    if(starta==enda-1)
    {
        printf("%c",b[bpos]);
        fflush(stdout);
        return;
    }
    for(int i=starta;i<enda;i++)
    {
        if(a[i]==b[bpos])
        {
            printf("%c",a[i]);
            fflush(stdout);
            print(starta,i,bpos-(enda-i));
            print(i+1,enda,bpos-1);
        }
    }
}

int main()
{
    //freopen("/home/myhyh/in","r",stdin);
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    scanf("%s%s",a,b);
    n=strlen(a);
    print(0,n,n-1);
}
