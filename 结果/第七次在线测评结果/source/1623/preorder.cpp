#include"stdio.h"
#include"string.h"
char zg[15], hg[15];
void xulie(int zl,int zr,int hl,int hr)
{
    int n=zl,i;
    if(zl>zr||hl>hr)
        return;
    printf("%c",hg[hr]);
    for(i=zl;i<=zr;i++)
        if(zg[i]==hg[hr])
        {
            n=i;
            break;
        }
    xulie(zl,n-1,hl,hl+n-zl-1);
    xulie(n+1,zr,hl+n-zl,hr-1);
}
main()
{
    int l;
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    scanf("%s %s",zg,hg);
    l=strlen(zg);
    xulie(0,l-1,0,l-1);
}
