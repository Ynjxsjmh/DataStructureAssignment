#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXL 11
char mid[MAXL],post[MAXL];

void pre(int ml,int mr, int pl,int pr)
{
	int i,pm;
	char root;
	if( ml > mr ) return;
	root=post[pr];
	//printf("%d %d %d %d\n",ml,mr,pl,pr);
	printf("%c",root);
	for(i=ml;i<=mr;i++)
	   if(mid[i]==root) break;
    pm = pl + (i-1 - ml);
	pre(ml,i-1,pl,pm);
	pre(i+1,mr,pm+1,pr-1);
}

int main()
{
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);	
	
	int len;
	
	scanf("%s %s",mid,post);
	len=strlen(mid);
	pre(0,len-1,0,len-1);
	printf("\n");
	
	return 0;
}
