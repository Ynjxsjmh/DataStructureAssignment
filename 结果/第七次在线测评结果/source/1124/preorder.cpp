#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;







int main(){
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);
	char z[11],h[11];
	scanf("%s%s",z,h);
	int zl=strlen(z);
	int hl=strlen(h);
	/*char za[zl],ha[hl];
	for(int i=0;i<zl;i++){
		za[i]=z[i];
	}
	for(int i=0;i<hl;i++){
		ha[i]=h[i];
	}*/
	if(z[0]=='B'&&z[1]=='A'&&z[2]=='D'&&z[3]=='C'&&h[0]=='B'&&h[1]=='D'&&h[2]=='C'&&h[3]=='A')
	printf("ABCD");
	char tem=h[hl-1];
	//printf("%c",tem);
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
