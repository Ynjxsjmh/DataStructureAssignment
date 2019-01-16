#include<stdio.h>
#include<stdlib.h>
int a[100];
int x;//dian
int t=1;
void init(int m,int n){
	a[n]=m;
} //¸¸Ç×Á¬ 
int fu(int m){
	if(a[m]=1)
		return t;
	t++;
	return a[m];
} 
int shen(){
	int i,max;
	int b[x];
	for(i=0;i<x;i++)
		b[i]=fu(i);
	max=b[0];
	for(i=0;i<x;i++){
		if(b[i]>max)
			max=b[i];
	}
	return max;	
}
int juli(int m,int n){
	int c[100],d[100],i=1,j=1,k;
	bool flag=true;
	c[0]=m;
	while(a[m]!=1){
		c[i]=a[m];
		m=a[m];
		i++;
	}
	c[i]=1;
	d[0]=n;
	while(a[n]!=1){
		d[j]=a[n];
		n=a[n];
		j++;
	}
	d[j]=1;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(c[i]==d[j]){
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	return 2*i+j;
}
int main(){
	a[1]=1;
	FILE *p;
	int i,j,a,b,m,n;
	p=fopen("tree.in","r");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fscanf(p,"%d",&x);
	for(i=0;i<x-1;i++){
		fscanf(p,"%d",m);
		fscanf(p,"%d",n);
		init(m,n);
	}
	fscanf(p,"%d",a);
	fscanf(p,"%d",b);
	FILE *q;
	q=fopen("tree.out","w");
	if(q==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fprintf(q,"%d\n",shen());
	fprintf(q,"%d\n",juli(a,b));
}
