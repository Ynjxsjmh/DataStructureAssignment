#include<iostream>
#include<fstream>
using namespace std;
#define cin fin;
#define cout fout;
ifstream fin("lottery.in");
ofstream fout("lottery.out");
 
class caipiao{
	int mai[7];
	int jiang[7];
	int count;//中了几个数 

	int out[7];//最后的显示 
	public:
		caipiao(){count=0;out[0]=0;out[1]=0;out[2]=0;out[3]=0;out[4]=0;out[5]=0;out[6]=0;}
		//~caipiao(){delete []mai};
		void jiangnumber();
		void zhonglesha();
		int outcount(){return count;}
		int outjiang(){return jiang[7];}
		void outout(){
			int ii;
			for(ii=0;ii<7;ii++)
			cout<<out[ii];}
		
};
void caipiao::jiangnumber(){
	int i;
	for(i=0;i<7;i++){
		cin>>jiang[i];
		if(jiang[i]<1||jiang[i]>33) cout<<"no,must be 1~33"<<endl;
	}	
}
void caipiao::zhonglesha(){
	int i;
	for(i=0;i<7;i++){
		cin>>mai[i];
		if(mai[i]<1||mai[i]>33) cout<<"no,must be 1 ~33！"<<endl;
	}
	int j;
	for(i=0;i<7;i++)
		for(j=0;j<7;j++){
			if(mai[i]==jiang[j]) count++;
		}
	if(count==1) out[6]++;
	if(count==2) out[5]++;
	if(count==3) out[4]++;
	if(count==4) out[3]++;
	if(count==5) out[2]++;
	if(count==6) out[1]++;
	if(count==7) out[0]++;
	count=0;//!!!!!!
}
int main(){
	int num;
	caipiao qqq;
	cin>>num;
	qqq.jiangnumber();
	int i;
	for(i=0;i<num;i++)
	qqq.zhonglesha();
	qqq.outout();
	return 0;
	
}
