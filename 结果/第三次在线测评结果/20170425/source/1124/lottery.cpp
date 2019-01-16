#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0;
	int count=0;
	int shuliang;
	scanf("%d",&shuliang);
	int jiang[7];
	for(int i=1;i<=7;i++) scanf("%d",&jiang[i-1]);
	int hao[shuliang][7];
	for(int p=0;p<shuliang;p++){
		for(int q=0;q<7;q++){
			scanf("%d",&hao[p][q]);
		}
	}
	int j;
	for(j=0;j<shuliang;j++){
		count=0;
		for(int k=0;k<7;k++){
			for(int m=0;m<7;m++){
				if(hao[j][k]==jiang[m])
				count++;
			}
		}
		if(count==7) a1++;
		if(count==6) a2++;
		if(count==5) a3++;
		if(count==4) a4++;
		if(count==3) a5++;
		if(count==2) a6++;
		if(count==1) a7++;
		if(count==0)  ;
	}
	printf("%d %d %d %d %d %d %d",a1,a2,a3,a4,a5,a6,a7);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
