#include <iostream>

using namespace std;
struct number{
long int n;
int q;
int wei;
};
struct number test[2000];
int shu[50000];

int main()
{	int i,j;
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);

for( i=0;i<2000;i++)
{test[i].q=0;
test[i].n=0;
test[i].wei=0;
}

int num;
cin>>num;
for( i=0;i<num;i++)
{
cin>>shu[i];
}

int now=0;
for( i=0;i<num;i++)
{
if(now==0)
{test[i].n=shu[i];
test[i].q++;
now++;
}
 else 
 { for(j=0;j<now;j++)
	{
         if(test[j].n==shu[i])
		 {  test[j].q++;
             break;
		 }
	}
   if(j==now)
   {
	   test[now].n=shu[i];
	   test[now].q++;
       now++;
   }


 }
}


for(i=0;i<now;i++)
for(j=0;j<now;j++)
{
if(test[i].n>test[j].n)
test[i].wei++;
}
for(i=0;i<now;i++)
{
	for(j=0;j<now;j++)
     if(i==test[j].wei)
   cout<<test[j].n<<" "<<test[j].q<<endl;
}


 


fclose(stdin);
fclose(stdout);
    return 0;
}
