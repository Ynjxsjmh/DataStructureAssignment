#include<fstream>
#include<iostream>
#include<queue>
#include<stack> 
using namespace std;
#define cin fin
#define cout fout
ifstream fin("tree.in");
ofstream fout("tree.out");  
class node{
	public:
	int x;
	int y;
};
int main(){
	int deep=1;//初始化 
	int wide=1;//初始化 
	int n;
	cin>>n;
	node *a;
	a=new node[n-1];//n-1条边 ,2(n-1)个数 
	int i;
	for(i=0;i<n-1;i++)
		cin>>a[i].x>>a[i].y;
	queue<node>qq;
	node item;
	for(i=0;i<n-1;i++)
		qq.push(a[i]);
	int count=0;
	item=qq.front();
	qq.pop();
	stack<int>ss;
	int *visit;
	int cou; //count的意思 
	visit=new int[2*(n-1)];
	for(i=0;i<2*(n-1);i++){
		if(visit[i]==1)cou++;
		if(visit[i]!=1){
			ss.push(a[i].x);
			ss.push(a[i].y);
	}
} 
	deep=cou-1;
	cout<<deep;
}
