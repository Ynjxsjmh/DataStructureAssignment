#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[1000][3];
int t,n=1;//记录输入多少个圆 
void f(){
	int i,j,k;
	for(i=0;i<t;i++){
		k=0;
		for(j=0;j<i;j++){
			if(sqrt((a[j][0]-a[i][0])*(a[j][0]-a[i][0])+(a[j][1]-a[i][1])*(a[j][1]-a[i][1]))<=a[i][2]+a[j][2]){
				break;
			}
			k++;
		}
		if(k==i-1&&k!=0)
			n++;
	} 
	FILE *p;
	p=fopen("circle.out","w");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fprintf(p,"%d",n);
}
int main(){
	FILE *p;
	int i,j;
	p=fopen("circle.in","r");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fscanf(p,"%d",&t);
	for(i=0;i<t;i++)
		for(j=0;j<3;j++)
			fscanf(p,"%d",&a[i][j]);
	f();
}
