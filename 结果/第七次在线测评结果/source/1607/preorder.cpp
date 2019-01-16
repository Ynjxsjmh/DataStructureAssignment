#include<stdio.h>
#include<string.h>

char mid[100],bac[100];

int dfs(int ml,int mr,int bl,int br)
{
	int i;
	if(mr < ml)return 0;
	printf("%c",bac[br]);
	if(mr <= ml)return 0;
	for(i = ml; i <= mr; i++)
	{
		if(mid[i] == bac[br])
		{
			dfs(ml,i-1,bl,br-(mr-i)-1);
			dfs(i+1,mr,br-(mr-i),br-1);
		}
	}
}

int main()
{
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);
	int n,m,i,j;
	scanf("%s%s",mid,bac);
	n = strlen(mid);
	dfs(0,n-1,0,n-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}