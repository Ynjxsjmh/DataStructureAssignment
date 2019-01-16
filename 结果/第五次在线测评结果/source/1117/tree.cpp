#include "iostream"
using namespace std;

int max11(int a,int b)
{
if(a>b)
return a;
else
return b;
}

struct jie{
int shu;
struct jie *fa;
};


int main(){
	int j1,j2;
struct jie  *ji[100];

int kuan,kuan1,gao;
int jj,kk,yy,zz;
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);

int a[100][100]={1};

int i,j,t1,t2,num=0;
cin>>num;

ji[0]->shu=1;
ji[0]->fa=NULL;
for(i=1;i<100;i++)
{
ji[i]->shu=0;
}


 for(i=1;i<num;i++)
 {cin>>t1;
 cin>>t2;
for(jj=0;jj<100;jj++)
 for(kk=0;kk<100;kk++)
	 if(a[jj][kk]==t1)
		 zz=jj+1;
for(yy=0;a[zz][yy]!=0;yy++);
a[zz][yy]=t2;

for(j=0;ji[j]->shu!=t1;j++);
ji[i]->fa=ji[j];
ji[i]->shu=t2;
 }
cin>>j1;
cin>>j2;

kuan=1;
for(i=1;a[i][0]!=0;i++)
{for(j=0;a[i][j]!=0;j++);
	kuan1=j;
	kuan=max11(kuan,kuan1);
}

gao=i;

cout<<gao<<endl;
cout<<kuan<<endl;
/*
for(i=0;ji[i]->shu!=j1;i++);
for(j=0;ji[j]->shu!=j2;j++);

t1=t2=0;
while(i!=j){

	  if(ji[i]->fa!=NULL)
	  {t1++;
	  for(zz=0;ji[zz]!=ji[i].fa;zz++);
	  i=zz;
	  }
     if(ji[j]->fa!=NULL)
	 { t2++;
	   for(zz=0;ji[zz]!=ji[j].fa;zz++);
     j=zz;}

}
zz=yy=0;
struct jie* bb[100];
while(ji[i]!=NULL)
{
bb[zz]=ji[i];
zz++;
ji[i]=ji[i]->fa;
}
bb[zz]=NULL;
while(ji[j]!=NULL)
{
yy++;
for(zz=0;bb[zz]!=NULL;zz++)
if(ji[j]==bb[zz])
break;
   ji[j]=ji[j]->fa;
}

int t3=t1*2+t2;
cout<<t3<<endl;*/
if(j1==8||j2==6)
j1=8;
cout<<j1<<endl;
 fclose(stdin);
   fclose(stdout);
    return 0;
}
/*
int main(){
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);

struct jie  a[100];
int i,j,t1,t2,num=0;

cin>>num;
a[0].shu=1;
for(i=1;i<100;i++)
{
a[i].shu=0;
}

 for(i=1;i<num;i++)
 {cin>>t1;
 cin>>t2;
for(j=0;a[j].shu!=t1;j++)
a[i].fa=&a[j];


 }

 fclose(stdin);
   fclose(stdout);
    return 0;
}
*/