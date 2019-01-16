#include <limits.h>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct node{
	int data;
	int num;
};

struct node a[50005];

//int cmp(const void *a,const void *b)
//{
//	return (*(node *)a).data>(*(node *)b).data? 1 : -1;
//}

bool cmp(node a , node b)  
{  
    if (a.data < b.data )  
    {  
        return true;  
    }
    return false ;  
}  


int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);	
	
	
	int flag;
	int node_length;
	int n,x;
	
	node_length=0;
	for(int i=0;i<50005;i++)
	{
		a[i].data=INT_MAX;
		a[i].num=0;
	}
	
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d",&x);
		flag=0;
		for(int i=0;i<node_length;i++)
		{
			if(a[i].data==x)
			{
				a[i].num++;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			a[node_length].data=x;
			a[node_length].num++;
			node_length++;
		}
	}
	
	sort(a , a+node_length , cmp);
	
	for(int i=0;i<node_length;i++)
		printf("%d %d\n",a[i].data,a[i].num);
	
	fclose(stdin);
	fclose(stdout);		
}
