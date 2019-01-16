#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
freopen("catchcow.in ","r",stdin);
freopen("catchcow.out","w",stdout);
fscanf(stdin,"%d%d",&n,&k);
if(n>=k)
fprintf(stdout,"%d",n-k);
fclose(stdin);
fclose(stdout);
return 0;
}
