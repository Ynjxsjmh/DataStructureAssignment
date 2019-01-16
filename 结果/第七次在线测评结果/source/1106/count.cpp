#include<iostream>
#include<fstream>
using namespace std;
#define cin fin;
#define cout fout;
ifstream fin("count.in");
ofstream fout("count.out");
int main(void){

	int a,m,k;
	int y;
	cin>>a;
	
	int Group[a];
	for(k=0;k<a;k++){
		cin>>m;
		Group[k]=m;
	}

	int j=0;
	for(int i=0;i<a;i++)
	for( j=0;j<a-1;j++)
	if(Group[j]>Group[j+1])
    {
    y=Group[j+1];
	Group[j+1]=Group[j];
	Group[j]=y;	
    }

    
    int p[a];
    int q[a];
    for(int w=0;w<a;w++)
    q[w]=0;
    int g=0,t=0,h,s=0;
    while(g<a){
    	p[s]=Group[g];
    	q[s]=q[s]+1;
    	t++;
		h=g;	
    	while((Group[h]==Group[h+1])&&(h<a)){
    		q[s]=q[s]+1;
			h++;	
		}
		g=h+1;
		s++;
    }
    for(int f=0;f<t;f++){
    	cout<<p[f];
    	cout<<"    ";
        cout<<q[f];
        cout<<endl;
	}



	return 0;
}
