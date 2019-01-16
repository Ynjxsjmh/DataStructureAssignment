#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int M = 123456;
long long a[M],ct,n;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(1+a,1+a+n);
    a[0]=a[1],a[n+1]=-1;
    for(int i=1;i<=n+1;i++){
        if(a[i]!=a[i-1])printf("%lld %lld\n",a[i-1],ct),ct=0;
        ct++;
    }
    return 0;
}
