#include<stdio.h>
#include<string.h>
char zhong[15],hou[15];
int zhuan(int l,char *a,char *b)
{
	if(l>0)
	{
		for(int i=l;i>0;i--)
		{
			if(a[i]==b[l])
			{
				printf("%c",a[i]);
				zhuan(i-1,a,b);
				zhuan(l-i,a+i,b+i-1);
			}
		}
	}
}
int main()
{
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);
	scanf("%s %s",zhong+1,hou+1);
	int len=strlen(hou+1);
	zhuan(len,zhong,hou);
	fclose(stdin);
	fclose(stdout);
}