#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
freopen("circle.in","r",stdin);
freopen("circle.out","w",stdout);
int x[7005],y[7005],r[7005];
int main(){
    int i=0,n,count1=1;
    double q;
scanf("%d",&n);
while(n--){
    scanf("%d%d%d",&x[i],&y[i],&r[i]);
    for(int j=0;j<i;j++){
        q=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        if(q<=r[i]+r[j])
            break;
        if(j==i-1)
            count1++;
    }
}
 printf("%d",count1);
fclose(stdin);
fclose(stdout);
return 0;
}
