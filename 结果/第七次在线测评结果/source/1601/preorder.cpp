#include<stdio.h>
#include<string.h>
int n;	
FILE *in, *out;
void create(int s, char *a, char *b)
{
	if(s==0) return;
	for(int i=0; i<s; i++)
	{
		if(a[i]==b[s-1])
		{
			fprintf(out, "%c", a[i]);
			create(i, a, b);
			create(s-i-1, a+i+1, b+i);
			
		}
	}
}
int main()
{
	int n;
	char mid[11], bac[11];

	in=fopen("preorder.in", "r");
	out=fopen("preorder.out", "w");
	fscanf(in, "%s", mid);
	fscanf(in, "%s", bac);
	n=strlen(mid);
	create(n, mid, bac);
	return 0;
} 