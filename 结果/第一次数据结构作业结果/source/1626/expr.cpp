#include<stdio.h>
#include<math.h>
#include<string.h>

char a[2005],c[2005];
int b[2005];

int jisuan(int shu1,char fu,int shu2)
{
	int jie;
	if(fu=='+')return shu1+shu2;
	if(fu=='-')return shu1-shu2;
	if(fu=='*')return shu1*shu2;
	if(fu=='/')return shu1/shu2;
}

int main()
{
	freopen("expr.in","r",stdin);
        freopen("expr.out","w",stdout);
	int k,i,topa=0,topb=0,topc=0,shu;
    char fu;
	scanf("%s",a);
	while(a[topa] != '=')
	{
		if('0' <= a[topa] && a[topa] <= '9')
		{
			shu = 0; 
			while('0' <= a[topa] && a[topa] <= '9')
			{
				shu *= 10;
				shu += a[topa] - '0';
				topa++;
			}
			b[topb]=shu;
			topb++;
		}
		else
		{
			while(topc > 0 && (a[topa]=='+' || a[topa]=='-') && c[topc-1]!='(' && c[topc-1]!=')')
			{
				b[topb-2] = jisuan(b[topb-2],c[topc-1],b[topb-1]);
				topb--;
				topc--;
			}
			while(topc > 0 && (a[topa]=='*' || a[topa]=='/') && (c[topc-1]=='*' || c[topc-1]=='/'))
			{
				b[topb-2] = jisuan(b[topb-2],c[topc-1],b[topb-1]);;
				topb--;
				topc--;
			}
			if(a[topa]==')')
			{
				while(c[topc-1] != '(')
				{
					b[topb-2] = jisuan(b[topb-2],c[topc-1],b[topb-1]);
					topb--;
					topc--;
				}
				topc--;
				topa++;
				continue;
			}
			c[topc]=a[topa];
			topc++;
			topa++;
		}
	}
	while(topc > 0)
	{
		b[topb-2] = jisuan(b[topb-2],c[topc-1],b[topb-1]);
		topb--;
		topc--;
	}
	printf("%d",b[0]);
}
