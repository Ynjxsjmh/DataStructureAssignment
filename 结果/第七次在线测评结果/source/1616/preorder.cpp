#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int M=123;
int A[M];
int B[M];
vector<int> G[M];
int work(int l,int r,int father){
    if(l>r) return 0;
    int K=0;
    for(int i=l;i<=r;i++)
        if(B[A[K]]<=B[A[i]]) K=i;

    G[father].push_back(A[K]);
    if(l==r)return 0;
    work(l,K-1,A[K]);
    work(K+1,r,A[K]);
    return 0;
}
int dfs(int num){
    if(num!=0)printf("%c",num+'A'-1);
    for(int i=0;i<G[num].size();i++)
        dfs(G[num][i]);
    return 0;
}
char s[M];
int main(){
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        A[i+1]=s[i]-'A'+1;
    }
    cin>>s;
    for(int i=0;i<len;i++){
        B[s[i]-'A'+1]=i;
    }
    work(1,len,0);
    dfs(0);
    printf("\n");
    return 0;
}
