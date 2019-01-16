#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		int loc;
		int time;
};
int oper(int n,int i)
{
	switch(i)
	{
		case 1:{
		
			return n-1;
			
			break;
		}
		case 2:return n+1;break;
		case 3:return n*2;
	}
}

int main()
{
	FILE* IN;
	FILE* OUT;
	if((IN=fopen("catchcow.in","r"))==NULL)
	{
		cout<<"open fail"<<endl;
		exit(0);
	}
	if((OUT=fopen("catchcow.out","w"))==NULL)
	{
		cout<<"write fail"<<endl;
		exit(0);
	}
	queue<node> aa;
	node be,en,temp,temp0;
	int n,i,k;
	n=0;
	fscanf(IN,"%d",&be.loc);
	fscanf(IN,"%d",&en.loc);

	int visited[100010];
	for(i=0;i<100010;i++)
	{
		visited[i]=0;
	}
	aa.push(be);
	visited[be.loc]=1;
	be.time=0;
	while(!aa.empty())
	{
		temp=aa.front();
		aa.pop();
		if(temp.loc==en.loc)
		{
			n=temp.time;
			break;
		}
		for(i=1;i<=3;i++)
		{
			temp0.loc=oper(temp.loc,i);
			temp0.time=temp.time+1;
			if(temp0.loc>=0&&visited[temp0.loc]!=1)
			{
				aa.push(temp0);
				
			}
		}
	}
	fprintf(OUT,"%d",n);

	return 0;
}
