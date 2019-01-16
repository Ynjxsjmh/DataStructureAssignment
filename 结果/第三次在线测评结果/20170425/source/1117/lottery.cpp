#include<iostream>
using namespace std;


struct cai{
long int a;
int p;
//struct cai *next;
};

struct cai ce[7];


int main(){
freopen("lottery.in","r",stdin);
freopen("lottery.out","w",stdout);

long int num;
scanf("%ld",&num);

int i,j;
long int a[7];
for( i=0;i<7;i++)
scanf("%ld",&(ce[i].a));
for( i=0;i<7;i++)
ce[i].p=1;

long int zhong[7]={0};

for(long int k=0;k<num;k++){
for( i=0;i<7;i++)
ce[i].p=1;
long int b[7];
int shu=0;
for( i=0;i<7;i++)
scanf("%ld",&b[i]);
for( i=0;i<7;i++)
 for(j=0;j<7;j++)
if(b[i]==ce[j].a&&ce[j].p==1)
 {shu++;
ce[j].p=0;
break;}

if(shu!=0)
zhong[7-shu]++;

}
for(i=0;i<6;i++)
printf("%ld ",zhong[i]);
printf("%ld\n",zhong[6]);

 fclose(stdin);
    fclose(stdout);
    return 0;
}