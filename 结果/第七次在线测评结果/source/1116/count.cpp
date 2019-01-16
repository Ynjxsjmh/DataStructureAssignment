#include<stdio.h>
#include<stdlib.h>
int n;
struct m{
	long int data;
	int count;
};
long int a[50000];//一共有多少个数 
int main(){
	bool flag;
	int k,i,j;
	
	FILE *p;
	p=fopen("count.in","r");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fscanf(p,"%d",&n);
	struct m b[n];
	struct m c;
	for(i=0;i<n;i++)
		fscanf(p,"%ld",&a[i]);
	for(i=0;i<n;i++){
		b[i].count=0;
		b[i].data=0;
	}
	for(i=0;i<n;i++){
		flag=true;
		for(j=0;j<n;j++){
			if(a[i]==b[j].data){
				(b[j].count)++;
				flag=false;
				break;
			}
		}
		if(flag){
			k=0;
			while(b[k].data!=0)
				k++;
		b[k].data=a[i];
		b[k].count=1; 
		} 
	}
	flag=true;
	while(flag){
		flag=false;
		for(i=0;i<n-1;i++){
			if(b[i].data>b[i+1].data){
				c=b[i];
				b[i]=b[i+1];
				b[i+1]=c;
				flag=true;
			}
		}
	}
	FILE *q;
	q=fopen("count.out","w");
	if(q==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	for(i=0;i<n;i++){
		if(b[i].data!=0)
			fprintf(q,"%ld %d\n",b[i].data,b[i].count);
	}
}

