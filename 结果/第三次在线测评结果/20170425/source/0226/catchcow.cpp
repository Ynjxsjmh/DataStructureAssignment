#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
const int  M  = 200000+123;
int n,K;
int vis[M];
struct pos{
    int num;
    int val;
    pos(int num=0,int val=0) : num(num),val(val){}
};

bool operator <  (pos A,pos B){
    return A.val>B.val;
}

priority_queue<pos>q;
int main(){
    freopen("catchcow.in","r",stdin);
   freopen("catchcow.out","w",stdout);
    cin>>n>>K;
    q.push(pos(n,0));
    vis[n]=1;
    while(!q.empty()){
        pos tmp=q.top();
        q.pop();
        int from=tmp.num;
        int dist=tmp.val;
        //printf("%d %d\n",from,dist);
        if(from==K){
            printf("%d\n",dist);
            break;
        }
        int to=from+1;
        if(to<M){
            if(!vis[to]){
                    vis[to]=1;
                    q.push(pos(to,dist+1));
            }
        }
        to=from-1;
        if(to>=0){
            if(!vis[to]){
                    vis[to]=1;
                    q.push(pos(to,dist+1));
            }
        }
        to=from*2;
        if(to<M){
            if(!vis[to]){
                    vis[to]=1;
                    q.push(pos(to,dist+1));
            }
        }
    }
    return 0;
}
