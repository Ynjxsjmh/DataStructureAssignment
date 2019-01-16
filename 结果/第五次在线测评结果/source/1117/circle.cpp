#include "iostream"
using namespace std;

struct yuan
{int xinx;
int xiny;
int ban;
int pan;
};
int main(){
	int t1,t2;
	
	int i,j,k;
freopen("circle.in","r",stdin);
freopen("circle.out","w",stdout);

struct yuan aa[7000];
for( i=0;i<7000;i++)
aa[i].pan=-1;

int num;
cin>>num;

for( i=0;i<num;i++)
{cin>>aa[i].xinx;
cin>>aa[i].xiny;
cin>>aa[i].ban;
aa[i].pan=0;
}
j=0;
k=1;
while(aa[j].pan!=-1)
{ if(aa[j].pan==0)
{ aa[j].pan=k;
k++;
 for(i=j+1;i<num;i++)
 {
   if(aa[i].pan==0)
   {t1=(aa[i].xinx-aa[j].xinx)*(aa[i].xinx-aa[j].xinx)+(aa[i].xiny-aa[j].xiny)*(aa[i].xiny-aa[j].xiny);
   t2=(aa[i].ban+aa[j].ban)*(aa[i].ban+aa[j].ban);
      if(t1<=t2)
	  {aa[i].pan=aa[j].pan;
	  }
   }

 }
}
j++;
}
k--;
cout<<k;
   fclose(stdin);
   fclose(stdout);
    return 0;
}