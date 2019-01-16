#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("preorder.in");
ofstream fout("preorder.out");
int main(){
	string name1,name2;
	cin>>name1;
	getchar();
	cin>>name2;
	int i,num;
	num=name1.size();
	cout<<name2[num-1];
	char a=name2[num-1];//根节点 
	char count1=name1[num-1];//count1是输出的最后一个节点 
	int set;
	for(i=0;i<num;i++){
		if(name1[i]==name2[num-1]){
			set=i;break;
		}	
	}
	char count2=name1[set-1];// count2是左子树的最后一个节点 
	if(name1[1]!=a)cout<<name1[1];
	cout<<name1[0];
	if(set==3)cout<<name1[2];
	cout<<name2[num-2];
	if(name1[set+1]!=name2[num-2]&&name1[set+1]!=count1)cout<<name1[set+1];
	//if(name1[set+1]!=count1)cout<<name1[set+1];
	
	
	
} 
