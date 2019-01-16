#include <iostream>
#include <fstream>
#define cin fin
#define cout fout 
#define M 200001 
using namespace std;
ifstream fin("catchcow.in");
ofstream fout("catchcow.out");

int N,K;
int d[M];
int q[M];
int f,r;

void extend(int x,int y)
{
	if(y>=0 && y <= 2*K && d[y] == -1)
	{
		d[y]=d[x]+1;
		q[r++]=y;
	}
}

int main()
{
	int i,t;
    cin>>N>>K;
    
    if(K<=N) {
		cout<<N-K<<endl;
		return 0;
    }
	
	for(i=0;i<=2*K;i++)d[i]=-1;
	d[N]=0;
	q[r++]=N; 

	while(f<r){
		t=q[f++];
		if(t==K) break;
        extend(t,t+1);
		extend(t,t+t);
		extend(t,t-1);		
	}
	//for(i=0;i<=2*K;i++)
	  //cout<<d[i]<<" ";
	cout<<d[K]<<endl;
	
	return 0;
}

