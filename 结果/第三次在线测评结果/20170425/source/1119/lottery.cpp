#include<iostream>
using namespace std;
int main()
{
	int jiang[8],win_num[7],num[7],n,i,j,k,r,x;
	FILE* IN;
	FILE* OUT;
	x=0;
	if((IN=fopen("lottery.in","r"))==NULL)
	{
		cout<<"oper fail"<<endl;
		exit(0);
	}
	if((OUT=fopen("lottery.out","w"))==NULL)
	{
		cout<<"write fail"<<endl;
		exit(0);
	}
	for(i=0;i<7;i++)
	{
		jiang[i]=0;
	}
	fscanf(IN,"%d",&n);
//	cin>>n;
	for(i=0;i<7;i++)
	{
		fscanf(IN,"%d",&win_num[i]);
//		cin>>win_num[i];
	}
	for(i=0;i<6;i++)
	{
		k=i;
		for(j=i+1;j<7;j++)
		{
			if(win_num[j]<win_num[k])
			{
				k=j;	
			}	
		}
		r=win_num[i];
		win_num[i]=win_num[k];
		win_num[k]=r;
	}
	while(n--)
	{
		x=0;
		for(i=0;i<7;i++)
		{
			fscanf(IN,"%d",&num[i]);
//			cin>>num[i];
		}
	/*	for(i=0;i<6;i++)
		{
			k=i;
			for(j=i+1;j<7;j++)
			{
				if(win_num[j]<win_num[k])
				{
					k=j;
				}
			}
		
	    	r=win_num[i];
		    win_num[i]=win_num[k];
		    win_num[k]=r;
		}*/
		for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
			{
				if(win_num[j]==num[i])
				{
					x++;
					break;
				}
			}
		}
		jiang[7-x]++;
	}
	for(i=0;i<7;i++)
	{
		fprintf(OUT,"%d ",jiang[i]);
//		cout<<jiang[i];
	}
}
