#include<iostream>
#include"stdio.h"
using namespace std;
int main(){
int aim[7],tem[7];
long a,b,c,d,e,f,g,n,h;
FILE*fp1,*fp2;
fp1=fopen("lottery.in","r");
fp2=fopen("lottery.out","w");
fscanf(fp1,"%d",&n);
a=b=c=d=e=f=g=0;
for(int i=0;i<7;i++)
    fscanf(fp1,"%d",&aim[i]);
for(int i=1;i<=n;i++){
    for(int i=0;i<7;i++)
      fscanf(fp1,"%d",&tem[i]);
    h=0;
    for(int k=0;k<7;k++){
        for(int p=0;p<7;p++){
            if(tem[k]==aim[p]){
                h++;
                break;
            }
        }

    }
    if(h==7) a++;
    if(h==6) b++;
    if(h==5) c++;
    if(h==4) d++;
    if(h==3) e++;
    if(h==2) f++;
    if(h==1) g++;
}
fprintf(fp2,"%d ",a);
fprintf(fp2,"%d ",b);
fprintf(fp2,"%d ",c);
fprintf(fp2,"%d ",d);
fprintf(fp2,"%d ",e);
fprintf(fp2,"%d ",f);
fprintf(fp2,"%d ",g);
fclose(fp1);
fclose(fp2);
return 0;
}
