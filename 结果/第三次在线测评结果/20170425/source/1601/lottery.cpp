#include<stdio.h>

int main() 
{
	FILE *in, *out;
	int j=1, k=0;
	int number=0;
	int a[100001], win[7];
	in=fopen("expr.in", "a+");
	fprintf(in, "\n");
	fclose(in);
	in=fopen("expr.in", "r");
	out=fopen("expr.out", "w");
	for(int l=0; l<100001; l++)a[l]=0;
	for(int m=0; m<7; m++)win[m]=0;
	while(!feof(in))
	{
		if(j==1)
		{
			j++;
			int i=0;
			char str[1001], ch;
			fgets(str, 1001, in);
			int n=ch-'0';
			ch=str[++i];
			while(ch>='0'&&ch<='9')
			{
				n=n*10+ch-'0';
				ch=str[++i];
			}
		}
		if(j>=2&&j<=8)
		{
			j++;
			int i=0;
			char str[1001], ch;
			fgets(str, 1001, in);
			ch=str[i];
			while(ch!='\0')
			{
				if(ch>='0'&&ch<='9')
				{
					int n=ch-'0';
					ch=str[++i];
					while(ch>='0'&&ch<='9')
					{
						n=n*10+ch-'0';
						ch=str[++i];
					}
					i--;
					a[k]=n;
					k++;
				} 
				else switch(ch)
				{
					case' ':break;
					case'\n':break;
				}
				ch=str[++i];
			}
		}
		if(j>8)
		{
			j++;
			int i=0, w=0;
			int b[100001];
			char str[1001], ch;
			fgets(str, 1001, in);
			ch=str[i];
			while(ch!='\0')
			{
				if(ch>='0'&&ch<='9')
				{
					int n=ch-'0';
					ch=str[++i];
					while(ch>='0'&&ch<='9')
					{
						n=n*10+ch-'0';
						ch=str[++i];
					}
					i--;
					b[w]=n;
					w++;
				} 
				else switch(ch)
				{
					case' ':break;
					case'\n':break;
				}
				ch=str[++i];
			}
			number=0;
			for(int h=0; h<=w; h++)
			{
				for(int p=0; p<=k; p++)
				{
					if(b[h]==a[p])number++;
				}
			}
			a[7-number]++;
		}
	} 
	fprintf(out, "%d \n", a);
	printf("%d", j);
	return 0;
}