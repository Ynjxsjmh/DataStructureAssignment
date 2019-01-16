#include<stdio.h>
#include <stdio.h>
typedef struct
{
	 int key;    /* 假设关键字的数据类型为整型*/ 
	 int data;   /* 假设记录的信息域的数据类型为字符型*/
}Record;

void   insertSort(Record  r[],  int length)
/* 对记录数组r做直接插入排序，length为数组中待排序记录的数目*/
{ 
	  int i,j;
	  for (i=2;  i<=length;  i++) 
	  {
		r[0]=r[i];      /*将待插入记录存放到监视哨r[0]中*/
		j=i-1;	         
		while (r[0].key< r[j].key )     /* 寻找插入位置 */
		{
			r[j+1]= r[j]; 
			j=j-1;
		}
		r[j+1]=r[0];		         /*将待插入记录插入到已排序的序列中*/
	  }
} 

int main()
{
	freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
	int i,j;
	Record r[20];
	int len;
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		scanf("%d",&j);
		r[i].key=j;
	}
	insertSort(r,len);
	  
	int index=1;
	for(int i=2;i<=len;i++)
	{
		if(r[i].key!=r[1].key)
			break;
		else
		{
			index++;
		}
	}
	printf("%d %d\n",r[1],index);
	//printf("%d\n",r[index+1].key);
	int num=1;
	for(int i=index+1;i<=len;i++)
	{
		if(r[i+1].key==r[i].key)
	  		num++;
	  	else
	  	{
	  		printf("%d %d\n",r[i].key,num);
			num=1;	
		}
	}
	  
	  //printf("直接插入排序输出：\n");
	  /*
	  for(i=1;i<=len;i++)
	  printf("%d ",r[i].key);
	  printf("\n");
	  */
	  return 0;
}

