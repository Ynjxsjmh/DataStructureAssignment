#include<fstream>
#include<iostream>

using namespace std;
#define cin fin
#define cout fout
ifstream fin("circle.in");
ofstream fout("circle.out");
class circle{
	public:
		int x;
		int y;
		int r;
		
};
int main() {
	int num;
	cin>>num;
	int kuai=1;
	circle *a;
	a=new circle[num];
	int *b;
	b=new int[num-1];
	int i;
	for(i=0;i<num-1;i++){
		b[i]=0;
	}
	for(i=0;i<num;i++){
		cin>>a[i].x>>a[i].y>>a[i].r;
	}
	int j;
	for(i=0;i<num;i++){
		if(i+1==num)break;
		for(j=0;j<num;j++){
			if(j+1==num)break;
			int aaa=(a[j].x-a[j+1].x)*(a[j].x-a[j+1].x)+(a[j].y-a[j+1].y)*(a[j].y-a[j+1].y);//圆心距 的平方 
			int chafang=(a[j].r-a[j+1].r)*(a[j].r-a[j+1].r);
			int hefang=(a[j].r+a[j+1].r)*(a[j].r+a[j+1].r);//和的平方 
			if(/*aaa>=chafang&&*/aaa<=hefang){
				b[j]=1;
			}	
		}
	}
	int count=0;
	for(i=0;i<num-1;i++){
		if(b[i]==0)count++;
	}		
	cout<<count+1;
	}
