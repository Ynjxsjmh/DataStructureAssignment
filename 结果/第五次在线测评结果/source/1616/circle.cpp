#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int M = 12345;
struct pos{
    long long x,y,r;
    pos(long long x=0,long long y=0,long long r=0):x(x),y(y),r(r){}
}P[M];
int f[M];
int findest(int num){
    return f[num]==num?num:f[num]=findest(f[num]);
}
int check(int A,int B){
    return (P[A].x-P[B].x)*(P[A].x-P[B].x)+(P[A].y-P[B].y)*(P[A].y-P[B].y)<=(P[A].r+P[B].r)*(P[A].r+P[B].r);
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>P[i].x>>P[i].y>>P[i].r;
        f[i]=i;
    }
    int ct=n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int A=findest(i);
            int B=findest(j);
            if(check(i,j)&&A!=B){
                f[A]=B;
                ct--;
            }
        }
    }
    printf("%d\n",ct);
    return 0;
}
