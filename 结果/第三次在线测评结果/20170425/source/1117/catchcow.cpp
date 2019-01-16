#include<iostream>
#include<stack>
using namespace std;

struct t{
	int  num;
	struct t *y;
	struct t *e;
	struct t *s;
};


int min(int a,int b){return (a<b)?a:b;}
int duan(struct t* a,int b){
	if(b<a->num)return (a->num)-b;
	if(a->num<0||a->num>1000)return 10000;
	if(b-a->num<4)return b-a->num;
if(a->num==b)return 0;
if(a->num+1==b||a->num-1==b||a->num*2==b)
return 1;
a->y=new struct t;
a->e=new struct t;
a->s=new struct t;
a->y->num=a->num+1;
a->s->num=a->num-1;
a->e->num=a->num*2;
int k1=duan(a->y,b);
int k2=duan(a->s,b);
int k3=duan(a->e,b);
return (1+min(min(k1,k2),k3));
}

int main(){
freopen("catchcow.in","r",stdin);
freopen("catchcow.out","w",stdout);
int a;
scanf("%d",&a);
int b;
scanf("%d",&b);
struct t aa;
aa.num=a;
printf("%d",duan(&aa,b));

fclose(stdin);
    fclose(stdout);
    return 0;
}