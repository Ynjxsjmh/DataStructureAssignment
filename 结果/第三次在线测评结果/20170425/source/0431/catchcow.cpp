#include<stdio.h>
int main(){
	FILE *p,*q;
	p=fopen("catchcow.in","r");
	q=fopen("catchcow.out","w");
	int a,b,c,d,e,k,time;
	fscanf(p,"%d%d",&a,&b);
	k=0;
	while(a*2<b){
		a=a*2;
		k++;
	}
	c=k;
	d=k;
	e=a;
	while(e!=b){
		c++;
		e++;
	}
	a=a*2;
	d++;
	while(a!=b){
		a--;
		d++;
	}
	if(c>d)
	 time=d;
	 else time=c;
	 fprintf(q,"%d",time);
	 return 0;
}
	
