#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
class circle{
	public:
		circle(int x1=0,int x2=0,int r0=0){
			x=x1;
			y=x2;
			r=r0;
		}
		int x,y;
		int r;
		~circle(){ }
};
int main (){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	int jisu=1;
	int n;
	scanf("%d",&n);
	circle *aa[n];
	for(int i=1;i<=n;i++){
	    int m,n,p;
		scanf("%d%d%d",&m,&n,&p);
		aa[i-1]=new circle(m,n,p);
	}
	for(int i=0;i<=n-1;i++){
		for(int j=i+1;j<n;j++){
			if(sqrt(((aa[i]->x-aa[j]->x)*(aa[i]->x-aa[j]->x))+((aa[i]->y-aa[j]->y)*(aa[i]->y-aa[j]->y)))>(aa[i]->r+aa[j]->r)){
				jisu++;
			}
		}
	}
	printf("%d",jisu);
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
