#include<stdio.h>
#include <stdio.h>
typedef struct
{
	 int key;    /* ����ؼ��ֵ���������Ϊ����*/ 
	 int data;   /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void   insertSort(Record  r[],  int length)
/* �Լ�¼����r��ֱ�Ӳ�������lengthΪ�����д������¼����Ŀ*/
{ 
	  int i,j;
	  for (i=2;  i<=length;  i++) 
	  {
		r[0]=r[i];      /*���������¼��ŵ�������r[0]��*/
		j=i-1;	         
		while (r[0].key< r[j].key )     /* Ѱ�Ҳ���λ�� */
		{
			r[j+1]= r[j]; 
			j=j-1;
		}
		r[j+1]=r[0];		         /*���������¼���뵽�������������*/
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
	  
	  //printf("ֱ�Ӳ������������\n");
	  /*
	  for(i=1;i<=len;i++)
	  printf("%d ",r[i].key);
	  printf("\n");
	  */
	  return 0;
}

