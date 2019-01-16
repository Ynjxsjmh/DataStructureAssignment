#include<bits/stdc++.h>
using namespace std;
const int M= 12345;
int st[M];
struct pos{
	int next,pre;
	int val;
}P[M];
int head=0;
int init(){//回收栈
	for(int i=1;i<M;i++) st[i]=i;
	return 0;
}

int build(){
	P[0].pre=-1;
	P[0].next=-1;
	return 0;
}
int insert(int num,int val){//插入
	 int K=0,k=0;
	 while(k<num){
	 	 K=P[K].next;
		 k++;
	 }
	 int n=st[++st[0]];
	 P[n].val=val;
	 P[n].next=P[K].next;

	 P[n].pre=K;
	 P[P[K].next].pre=K;
	 P[K].next=n;
	//printf("CC%d %d %d %d\n",n,P[n].next,K,P[K].next);
	 return 0;
}

int find1(int num){//查找
	int K=P[head].next,k=1;
	while(k<num){
	 	 K=P[K].next;
		 k++;
	}
	return P[K].val;
}

int del(int num){//删除
	 int K=P[head].next,k=1;
	 while(k<num){
	 	 K=P[K].next;
		 k++;
	 }
	 P[P[K].pre].next=P[K].next;
	 P[P[K].next].pre=P[K].pre;
	 st[--st[0]]=K;
	 return 0;
}

int find2(int val){
	int K=0,k=0;
	while(P[K].val!=val){
		K=P[K].next;
		k++;
	}
	return k;
}

int prin(){
	int K=P[head].next;
	//printf("CCS%d\n",P[1].next);
	while(K!=-1){
		printf("%d ",P[K].val);
		K=P[K].next;
	}
	printf("\n");
	return 0;
}

int main(){
	init();
	build();
	for(int i=1;i<=10;i++){
		//printf("%d\n",i);

		insert(i-1,10+1-i);
		//printf("CCS%d\n",P[1].next);
		prin();
	}
	del(2);
	prin();
	printf("%d\n",find2(5));

	prin();
	printf("%d\n",find1(4));

	prin();
	return 0;
}
