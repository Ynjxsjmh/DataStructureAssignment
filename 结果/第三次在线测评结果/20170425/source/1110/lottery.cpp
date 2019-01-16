#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
freopen("lottery.in","r",stdin);
freopen("lottery.out","w",stdout);
int a[10],b[10],c[10],i,h,j,n;
for(i=0;i<9;i++)
    c[i]=0;
fscanf(stdin,"%d",&n);
for(i=0;i<7;i++)
 fscanf(stdin,"%d",&a[i]);
 sort(a,a+7);
while(n--){
    h=0;
for(i=0;i<7;i++)
fscanf(stdin,"%d",&b[i]);
 sort(b,b+7);
for(i=0;i<7;i++)
for(j=0;j<7;j++)
{if(a[i]==b[j])
    {h++;
    break;}
    if(b[j]>a[i])
    break;
}
c[h]++;
}
for(i=7;i>=1;i--)
fprintf(stdout,"%d",c[i]);
fclose(stdin);
fclose(stdout);
return 0;
}
