#include<iostream>
#include<cstdio>
using namespace std;

void qsort(int*a,int m,int n){
	int i,j,k,temp;
	if(m<n){
		i=m;
		j=n+1;
		k=a[m];
		while(i<j){
			i++;
			while(a[i]<k) i++;
			j--;
			while(a[j]>k) j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[m];
		a[m]=a[j];
		a[j]=temp;
		qsort(a,m,j-1);
		qsort(a,j+1,n);
	}
}


int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	int jishu[n];
    for(int i=0;i<n;i++){
    	scanf("%d",&jishu[i]);
	} 
	qsort(jishu,0,n-1);
	int countt=1;
	int shu;
	shu=jishu[0];
	for(int i=1;i<n;i++){
		if(shu==jishu[i]) countt++;
		else{
			printf("%d %d\n",shu,countt);
			shu=jishu[i];
			countt=1;
		}
	}
	
	printf("%d %d\n",shu,countt);
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
