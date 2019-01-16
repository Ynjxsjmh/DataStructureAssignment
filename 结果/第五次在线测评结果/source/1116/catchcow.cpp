#include<stdio.h>
#include<queue>
#include<stdlib.h>
#define maxn 100005
using namespace std;
int v[maxn];//判断是否到达过
int step[maxn]; 
queue<int>q;
int f(int i,int j){
	int n;
	int head,next;
	q.push(i);
	step[i]=0;
	v[i]=1;
	while(!q.empty()){
		head=q.front();
		q.pop();
		for(n=0;n<3;n++){
			if(n==0)
				next=head-1;
			else if(n==1)
				next=head+1;
			else
				next=head*2;
			if(next<0||next>=maxn)
				continue;
			if(!v[next]){
				q.push(next);
				step[next]=step[head]+1;
				v[next]=1;
			}
			if(next==j)
				return step[next]; 
		}
	}
}
int main(){
	int i,n,m,k;
	for(i=0;i<100005;i++){
		v[i]=0;
	}
	FILE *p;
	p=fopen("catchcow.in","r");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fscanf(p,"%d",&n);
	fscanf(p,"%d",&m);
	if(n>=m)
		k=n-m;
	else
		k=f(n,m);
	FILE *q;
	q=fopen("catchcow.out","w");
	if(q==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fprintf(q,"%d",k);
	return 0;
}
