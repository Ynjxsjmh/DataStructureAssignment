#include <iostream>
#include<cstring>
using namespace std;

struct tree{
char aa;
struct tree *z;
struct tree *y;
};

char zhong1[100];
char zhong2[100];

tree test[100];
void mm(char *a,char *b,int num,char *z,int now)
{if(num==0)
return;
	z[now]=b[num-1];
now++;
if(num==1)
return;

int ii;
for(ii=0;a[ii]!=b[num-1];ii++);
a[ii]='\0';
mm(a,b,ii,z,now);
mm(a+ii+1,b+ii,num-ii-1,z,now);
return;
}

int main(){
int now;
	now=0;
int kk;
	kk=0;
	int i,j;
freopen("preorder.in","r",stdin);
freopen("preorder.out","w",stdout);
char a[100];
char b[100];
char *q=a;
scanf("%s",a);
scanf("%s",b);


for(i=0;a[i]!=0;i++);
if(i==1){
printf("%s",a);
return 0;}
int num=i;

zhong1[now]=b[num-1];
//b[num-1]='\0';
now++;
int ii;
for(ii=0;a[ii]!=b[num-1];ii++);
a[ii]='\0';
mm(a,b,ii,zhong1,now);
mm(a+ii+1,b+ii,num-ii-1,zhong2,kk);

for(i=0;zhong1[i]!=0;i++)
cout<<zhong1[i];
for(i=0;zhong2[i]!=0;i++)
cout<<zhong2[i];
fclose(stdin);
fclose(stdout);
    return 0;
}