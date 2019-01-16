#include<iostream>
#include<cstring>
#include<queue>
#include"stdio.h"
using namespace std;

int main(){
int max=100020;
int hasvisited[100020]={0};
int n,k;
FILE*fp1,*fp2;
fp1=fopen("catchcow.in","r");
fp2=fopen("catchcow.out","w");
fscanf(fp1,"%d",&n);
fscanf(fp1,"%d",&k);
if(n>k){
    fprintf(fp2,"%d",n-k);
    return 0;
}
memset(hasvisited,0,sizeof(hasvisited));
queue<int> q;
q.push(n);
int t=0;
while(!q.empty()){
    t=q.front();
    q.pop();
    if(t==k){
        break;
    }
    if(t<k&&!hasvisited[t+1]){
        q.push(t+1);
        hasvisited[t+1]=hasvisited[t]+1;
    }
    if(t>0&&!hasvisited[t-1]){
        q.push(t-1);
        hasvisited[t-1]=hasvisited[t]+1;

    }
    if(2*t<max&&!hasvisited[2*t]){
        q.push(2*t);
        hasvisited[2*t]=hasvisited[t]+1;
    }
}
fprintf(fp2,"%d",hasvisited[t]);
fclose(fp1);
fclose(fp2);
return 0;
}
