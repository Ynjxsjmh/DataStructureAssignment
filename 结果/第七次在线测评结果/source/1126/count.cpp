#include <cstdio>
#include <iostream>
int a[50005];
int main(){
	
	
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);	
	
	
int num,x;
scanf("%d",&num);

int i;
memset(a, 0, sizeof(a));

for(i=0;i<num;i++)
{
 scanf("%d",&x);
 a[x]++;
}
for(i=0;i<50005;i++)
{
	if(a[i]!=0)
	printf("%d %d\n",i,a[i]);		
}
	   	
fclose(count.in);
fclose(count.out);
return 0;
	
	
}