#include<stdio.h>

int main()
{
	freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
	int a[7],b[34],c[7],d[8],i,j,k,m,n;//m��ʾĿǰ���˶��ٸ����� 
	scanf("%d",&n);
	b[0]=0;
	for(j=1;j<=33;j++)
	{
		b[j]=0;
	}
	//�н����� 
	for(i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]=1;
	}
	//�н���������ʼ��
	for(i=0;i<8;i++)
	{
		d[i]=0; 
	} 
	//��ĺ��� 
	for(k=0;k<n;k++)
	{
		m=0;
		for(i=0;i<7;i++)
		{
			scanf("%d",&c[i]);
			if(b[c[i]]==1)
				m++;
		}
		d[7-m]++;
	}
	for(i=0;i<7;i++)
	{
		printf("%d ",d[i]);
	}
	
	return 0;
}
