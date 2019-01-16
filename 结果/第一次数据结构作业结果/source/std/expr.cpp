#include <iostream>
#include <cstdio>
#define MAXN 101
using namespace std;
char e[MAXN];
char ostack[MAXN];
int otop=-1;
int nstack[MAXN];
int ntop=-1;

int pr[7][7]={{1,1,-1,-1,-1,1,1},
              {1,1,-1,-1,-1,1,1},
              {1,1,1,1,-1,1,1},
              {1,1,1,1,-1,1,1},
              {-1,-1,-1,-1,-1,0,2},
              {2,2,2,2,2,2,2},
              {-1,-1,-1,-1,-1,2,0}
			  };
inline int ord(char c)
{
	int d;
	switch(c){
		case '+': d=0;break;
		case '-': d=1;break;
		case '*': d=2;break;
		case '/': d=3;break;
		case '(': d=4;break;
		case ')': d=5;break;
		case '=': d=6;break;
	}
	return d;
}

inline int cpu(char o,int e1,int e2)
{
	int d;
	switch(o){
		case '+': d=e1+e2;break;
		case '-': d=e1-e2;break;
		case '*': d=e1*e2;break;
		case '/': d=e1/e2;break;
	}
	return d;
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);

	int i,d,e1,e2;
	char o;
	cin>>e;
	
	ostack[++otop]='=';
	for(i=0;e[i]!='\0';i++)
	{
	  if(e[i]>='0' && e[i]<='9'){
	  	 d=0;
	  	 while(e[i]>='0' && e[i]<='9'){
	  	 	d=d*10+e[i]-'0';
	  	 	i++;
	  	 }
	  	 nstack[++ntop]=d;	
	  }
	  
	  while(pr[ord(ostack[otop])][ord(e[i])]==1){
	  	 e2=nstack[ntop--];
	  	 e1=nstack[ntop--];
	  	 o=ostack[otop--];
	  	 nstack[++ntop]=cpu(o,e1,e2);
	  }
	  
	  if(pr[ord(ostack[otop])][ord(e[i])]==-1)
	  	 ostack[++otop]=e[i];
	  
	  if(pr[ord(ostack[otop])][ord(e[i])]==0)
	  	 ostack[otop--];	 
	}
	
	cout<<nstack[ntop--]<<endl;
	
	return 0;
}
