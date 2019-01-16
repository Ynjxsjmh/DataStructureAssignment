#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char s1[110],s2[110];
int pos1[310],pos2[310];
void build(int l1,int r1,int l2,int r2)
{
    //printf("%d %d %d %d\n",l1,r1,l2,r2);
    //system("pause");
    if(l1>r1) return;
    if(l2>r2) return;
    printf("%c",s2[r2]);
    if(l1==r1||l2==r2) return;
    int p1=pos1[s2[r2]];
    int siz1=p1-l1;
    build(l1,p1-1,l2,l2+siz1-1);

    int siz2=r1-p1;
    build(p1+1,r1,r2-siz2,r2-1);
}
int main()
{
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    scanf("%s%s",s1+1,s2+1);
    int n=strlen(s1+1);
    for(int i=1;i<=n;i++) pos1[s1[i]]=i;
    for(int i=1;i<=n;i++) pos2[s2[i]]=i;
    build(1,n,1,n);
    printf("\n");
    return 0;
}
/*
BAFDGCE BFGDECA
*/
