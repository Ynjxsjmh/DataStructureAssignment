#include <stdio.h>
#include <stdlib.h> 
int compare(const void *a,const void *b)
{
     return *(int*)a-*(int*)b;   
}

int main(void){
	FILE *In, *Out;
	In = fopen("count.in","r");
	int n; 
	long a[50000];
	fscanf(In,"%d",&n);
	for(int i = 0; i < n; i++)
		fscanf(In, "%d", &a[i]);
	fclose(In);
	qsort((void *)a,n,sizeof(long),compare);
	long b[50000][2];
	int bp = 0;
	b[0][0] = a[0];
	b[0][1] = 1;
	for(int i = 1; i < n; i++){
		if(a[i] == b[bp][0]){
			b[bp][1]++;
		}
		else{
			b[++bp][0] = a[i];
			b[bp][1]++;
		}
	}
	Out = fopen("count.out","w"); 
	for(int i = 0; i <= bp; i++){
		fprintf(Out, "%d %d\n",b[i][0],b[i][1]);
	}
	fclose(Out);
	
}
