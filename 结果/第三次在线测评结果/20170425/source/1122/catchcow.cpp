#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
void result(int n,int k){
    if(n>=k){printf("%d",n-k);return;}
    int sign[100000]={0};
    int step[100000]={0};
    int now,temp;
    queue<int> q;
    q.push(n);
    sign[n]=1;
    now=n;
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0){
                temp=now-1;
            }
            else if(i==1){
                temp=now+1;
            }
            else{
                temp=now*2;
            }
            if(sign[temp]==0){
                sign[temp]=1;
                step[temp]=step[now]+1;
                q.push(temp);
            }
            if(temp==k){
                printf("%d",step[temp]);
                return;
            }
    }
}
}
int main(){
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    result(n,k);
    fclose(stdin);
    fclose(stdout);
}
