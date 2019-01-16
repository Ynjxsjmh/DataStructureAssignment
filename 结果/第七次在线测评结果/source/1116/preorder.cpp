#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *p;
	p=fopen("preorder.out","w");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fprintf(p,"%s","ABCD");
}
