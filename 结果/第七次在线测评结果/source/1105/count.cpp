#include<iostream>
#include<fstream>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("count.in");
ofstream fout("count.out");
int main(){
	int num;
	cin>>num;
	long int*a=new long int[num];
	
	int i,j;
	long int k;
	int countnum;
	for(i=0;i<num;i++){
		
		cin>>a[i];
		}
	for(j=0;j<num-1;j++){
		countnum=0;
		for(i=0;i<num-1;i++){
			if(a[i]>a[i+1]){
				countnum++;
				k=a[i+1];
				a[i+1]=a[i];
				a[i]=k;
		}
	}
	if(countnum==0)break;
	}
	int flag=0;
	for(i=0;i<num;i++){
		if(i!=num-1&&a[i]!=-1)
			for(j=i+1;j<num;j++){
				if(a[i]==a[j]){flag++;a[j]=-1;}	
		}
		if(a[i]!=-1)cout<<a[i]<<" "<<flag+1<<endl;
			flag=0;
	}
	delete []a;
	
	return 0;
}
