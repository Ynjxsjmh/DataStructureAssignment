#include <stdlib.h>
#include <iostream>
using namespace std;

class seqlist{
	private:
		int maxsize;
		int length;
		int *base;
	public:
		seqlist(){ length=0;	};
		~seqlist(){ if(base==NULL)  delete []base;}
		void creat();
	    void del();
	    void insert();
	    int store();
	    void search();
	    void output();
};

void menu();

int main()
{
	seqlist l;
	int choose,storage;
	menu();
	while(scanf("%d",&choose)&&choose)
	{
	    switch(choose)
	    {
		    case 1:l.creat(); break;
		    case 2:l.insert(); break;
		    case 3:storage=l.store(); break;
		    case 4:l.del(); break;
		    case 5:l.search();
	    }
	    printf("\n\n\n\n");
	    menu();
    }
	return 0;
}

void seqlist::creat()
{
	printf("����������Ҫ�����Ľڵ����:");
	scanf("%d",&maxsize);
	base=new int[maxsize]; 
	printf("˳������ɹ���������%d���ڵ㣡",maxsize);
}

void seqlist::insert()
{
	int data,i,j;
	if(length==maxsize)
	{
		printf("\n�����Ա��������޷���������ڵ㣡");
		return ;
	}
	printf("���������������ڵ��λ���Լ�ֵ��������ǵ�һ�ε��øú����������0�ڵ㴦��ʼ���룩��\n");
	printf("����-1 -1���ɽ�������\n");
	scanf("%d%d",&i,&data);
	while(i!=-1&&data!=-1)
	{
		while(i>maxsize||i<-1||(i==-1&&data!=-1))
		{
			if(i>maxsize)
			{
				printf("����ڵ�λ�ó�������������˳�������ڵ���%d,�������������������ڵ��λ���Լ�ֵ:\n",maxsize);
				scanf("%d%d",&i,&data);
			}
			if(i<-1||(i==-1&&data!=-1))
			{
				printf("����ڵ�λ��С��˳����һ���ڵ�λ��0���������������������ڵ��λ���Լ�ֵ:\n");
				scanf("%d%d",&i,&data);
			}
		}	
		
		for(j=length-1;j>i;j--)
		{
			base[j+1]=base[j];
		}
		
		base[i]=data;
		length++;
		
		printf("λ��Ϊ%d,ֵΪ%d�Ľڵ����ɹ���\n",i,data);
		
		printf("\n");
		printf("����˳����е����нڵ�Ϊ:\n");
		output();
		printf("\n");
		
		
		if(length==maxsize)
		{
			printf("\n�����Ա��������޷���������ڵ㣡\n");
			return ; 
		}
		else
		{
			printf("�����������һ������Ҫ����Ľڵ��λ�ü���ֵ(���������������������-1 -1):");
			scanf("%d%d",&i,&data);
		}
	}
	
}

void seqlist::output()
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("λ��ֵΪ%d�Ľڵ��ֵΪ��%d\n",i,base[i]);
	}	
}

void seqlist::search()
{
	int flag=1;
	int k;

	while(flag)
	{
		printf("������������Ҫ���ҵ�Ԫ��ֵ:");
	    scanf("%d",&k);
	    
		int i,count=0;
		for(i=0;i<length-1;i++)
		{
			if(k==base[i])
			{
				printf("����Ҫ���ҵ�Ԫ��%d��˳����е�λ���ǣ�%d,�����ǵ�%d���ڵ㡣",k,i,i+1);
				count++;
			}
		}
		if(!count)
		{
			printf("����Ҫ���ҵ�Ԫ��%d�������ڸ�˳�����!\n\n",k);
		}
		else
		{
			printf("\n����Ԫ�سɹ���\n\n");
		}
		
		printf("������Ƿ�������ң�������������1���˳���������0��:");
		scanf("%d",&flag);
		while(flag!=0&&flag!=1)
		{
			printf("ѡ�����,��������������ѡ�񣨼�����������1���˳���������0����");
			scanf("%d",&flag);
		}
	}
}

void seqlist::del()
{
	int i,loc;
	int flag=1;
	
	while(flag)
	{
		
		printf("\n");
		printf("����˳����е����нڵ�Ϊ:\n");
		output();
		printf("\n");		
		
		
		
		printf("����������Ҫɾ���ڵ��λ��:");
		scanf("%d",&loc);
		
		while(loc<0||loc>length-1)
		{
			if(loc>length-1)
			{
				printf("ɾ���ڵ�λ�ó������Ա�����Ԫ�ص����λ��ֵ:%d,����������������ɾ���ڵ��λ��:\n",length-1);
				scanf("%d",&loc);				
			}
			if(loc<0)
			{
				printf("ɾ���ڵ�λ��С��˳����һ���ڵ�λ��0������������������ɾ���ڵ��λ��:\n");
				scanf("%d",&loc);			
			}
		}
		
		if(length==0)
		{
			printf("\n˳���Ϊ�գ��޷���������ɾ������!\n");
			return ;
		}
		
		for(i=loc+1;i<length;i++)
		{
			base[i-1]=base[i]; 
		}
		
		length--;
		
		
		printf("\n");
		printf("����˳����е����нڵ�Ϊ:\n");
		output();
		printf("\n");
		
		
		
		if(length==0)
		{
			printf("\n˳���Ϊ�գ��޷���������ɾ������!");
			return ;
		}
		
		printf("������Ƿ����ɾ��������ɾ������1���˳�ɾ������0��:");
		scanf("%d",&flag);
		printf("\n");
		while(flag!=0&&flag!=1)
		{
			printf("\nѡ�����,��������������ѡ�񣨼���ɾ������1���˳�ɾ������0����");
			scanf("%d",&flag);
		}
	}
}

int seqlist::store()
{
	int k;
	printf("����������Ҫ��ȡ�Ľڵ��λ��:");
	scanf("%d",&k);
	return base[k];
}

void menu()
{
	printf("------------------------------------------------\n");
	printf("\t��ѡ������������Ҫ�Ĺ��ܣ�\n");
	printf("*1.����������M���ڵ��˳���\n");
	printf("*2.��˳����е�k���������һ���½��\n");
	printf("*3.��ȡ˳����е�k������ֵ\n");
	printf("*4.ɾ��˳����е�k�����\n");
	printf("*5.˳�����ֵΪx��Ԫ����˳����е�λ�ã��±꣩\n");
	printf("------------------------------------------------");
	printf("\n��ѡ��������Ҫ�Ĺ���(����0�����˳�):");
}
