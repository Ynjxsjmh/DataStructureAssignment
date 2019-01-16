#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
char a[20],b[20];
void solve(int d,int e,int f,int g){
    int i;
    if(d>e)
        return;
    putchar(a[e]);
    for(i=f;b[i]!=a[e];i++);
    solve(d,e-g+i-1,f,i-1);
    solve(e-g+i,e-1,i+1,g);
    }
int main(){
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    scanf("%s",b);
    scanf("%s",a);
    int leng=strlen(a);
    solve(0,leng-1,0,leng-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
