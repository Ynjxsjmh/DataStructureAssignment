#include<stdio.h>
#include<string.h>
preorder(char*a,char *b,int sin,int ein,int sbe,int ebe )
{
    int i;
    if(sin>ein || sbe>ebe)
        return 0;
    printf("%c",b[ebe]);
    for(i=sin;i<=ein;i++)
    {
        if(a[i]==b[ebe])
             break;
    }

    preorder(a,b,sin,i-1,sbe,sbe+i-sin-1);
    preorder(a,b,i+1,ein,sbe+i-sin,ebe-1);


}
int main()
{
     freopen("preorder.in","r",stdin);
     freopen("preorder.out","w",stdout);
    int n,m;
    char a[15],b[15];
    scanf("%s",a);
    scanf("%s",b);
    n=strlen(a);
    m=strlen(b);
   preorder(a,b,0,n-1,0,m-1);
}
