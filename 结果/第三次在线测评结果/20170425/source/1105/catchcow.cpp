#include<iostream>
#include<fstream>
using namespace std;
#define cin fin;
#define cout fout;
ifstream fin("catchcow.in");
ofstream fout("catchcow.out");
int zheng(int a){
	if(a>=0)return a;
	if(a<0)return -1*a;
}
int main(){
	int n;
	int k;
	int min;
	cin>>n>>k;
	if(n>=k)
		min=n-k;
	int i;
	int nf;
	if(n<k){
	for(i=0;i<1000;i++){
	    nf=zheng(i*n-k)+i;
	    if(nf<=(n-k))
		min=nf;
		else min=n-k; 
	}
	cout<<min;	
	}}

