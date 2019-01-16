#include<iostream>
#include<fstream>
using namespace std;
#define fin cin;
#define fout cout;
class member{
	int x;
	int y;
	int r;
	int relation;
	public:
		member(int a,int b,int c):x(a),y(b),r(c){}
		int getx(){return x;}
		int gety(){return y;}
		int getr(){return r;}
		void putx(int a){x=a;}
		void puty(int a){y=a;}
		void putz(int a){r=a;}
};
int main(void){
	ifstream fin("circle.in");
	ofstream fout("circle.out");
	bool judge(member a,member b);
	int positive(int a,int b);
	int n,x,y,r,i,j=0,k=0,l=0,m=0,final;
	int sum=0;
	member **A;
	member *a;
	cin>>n;
    for(i=0;i<n;i++){
    	cin>>x;
    	cin>>y;
    	cin>>r;
    	a[i]=new member(x,y,r);
	}
	i=0;
	if(n==1)
	final=1;
	else  {
	    if(n==2){
		if(judge(a[0],a[1]))
		final=2;
		else 
		final=1;
    	}
    cout<<final;
    return 0;
}
  /*  	while(i<n){
    		member *p=NULL;
    		for(i=0;i<n;i++){
    			for(j=0;j)
    		p[]
			}
		}
	/*	while(i<n){
		m=i;	
		member *p=A[j];
		for(k=0;k<n;k++){
			if(judge(a[i],a[k])){
			i=i+1;
			p[i]=a[k];	
			}
		}
		j++;
		m++;
		i=m;
	    }
	    i=0;
	    j
		
		
		/*while(i<n){
		for(l=0;l<sum;l++){
			
		}	*/

bool judge(member a,member b){
	int d;
	int R;
	d=pow((a.getx()-b.getx())*(a.getx()-b.getx())+(a.gety()-b.gety())*(a.gety()-b.gety()))
	R=positive(a.getr(),b.getr());
	if(d>R)
	return false;
	else 
	return true;
}
int positive(int a,int b){
    if(a==b)
    return 0;
    else if(a>b)
    return a-b;
    else if(a<b)
    return b-a;
}

