#include <stdio.h>
#include <stdlib.h>
int a[7];//�н�����
int b[1000][7];//��������
int c[1000];//�н��������
int d[7];
int t;//��¼�ж����Ų�Ʊ 
void f(){
	int i,j,k,m=0;
	 for(i=0;i<t;i++){//ÿ�� 
	 	for(j=0;j<=6;j++){//ÿλ  
	 		for(k=0;k<=6;k++){
	 			if(b[i][j]==a[k]){
	 				c[i]++;
	 				break;
				 }	
			 }
	 	} 
	} 
	for(i=0;i<t;i++){
		if(c[i]==1)
			d[6]++;
		else if(c[i]==2)
			d[5]++;
		else if(c[i]==3)
			d[4]++;
		else if(c[i]==4)
			d[3]++;
		else if(c[i]==5)
			d[2]++;
		else if(c[i]==6)
			d[1]++;
		else if(c[i]==7)
			d[0]++;
	}
	FILE *p;
	p=fopen("lottery.out","w");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	for(i=0;i<6;i++)
		fprintf(p,"%d ",d[i]);
	fprintf(p,"%d\n",d[i]);
}
int main(){
	int i,j;
	FILE *p;
	p=fopen("lottery.in","r");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fscanf(p,"%d",&t);
	for(i=0;i<7;i++){
		fscanf(p,"%d",&a[i]);
	}
	for(i=0;i<t;i++)
		for(j=0;j<7;j++)
			fscanf(p,"%d",&b[i][j]);
	f();
} 
