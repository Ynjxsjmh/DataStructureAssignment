#include <iostream>
#include <iomanip>
#include <fstream>
#define cin fin
#include cout fout
using namespace std;
ifstream fin("count.in");
ofstream fout("count.out")
int main(void)
{
	int a[1000],b[1000],c[1000];
	int n;
	//cout<<"����n��ֵ"<<endl;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0;i<1000;i++)
		c[i] = 1;
	int j = 0;//��¼����b����
	int k;
	int w;
	for(i = 0;i < n;i++)
	{
		if(i == 0)
		{
			w = b[j] = a[i];
		///	cout<<"ddddd"<<endl;
			for(k = 1;k < n;k++)
			{
				//cout<<"������������������"<<endl;
			//	cout<<j;
				if(a[k] == a[0])
				{
				//	cout<<"qqqqq"<<endl;
					c[w] = c[w] + 1;//��¼��һ�����������������ж��ٸ�
				}
			}
			j++;
		}
		else
		{
			int v = 0;//�ж�b�������Ƿ������������
		//	cout<<"��������Ⱥ"<<endl;
			for(int q = 0;q < j;q++)
				if(a[i] == b[q])
					v++;
			if(v == 0)
			{
				w = b[j] = a[i];
				for(int r = i+1;r < n;r++)
				{
					if(a[r] == b[j])
						c[w]++;
				}
				j++;
			}
		}
	}
	//�������
	int temp;
	//cout<<"�������"<<endl;
	for(int y = 0;y < j;y++)
	{
		for(int p = 0;p < j-i;p++)
		{
			//cout<<"wwwwwwwwwwwwwwww"<<endl;
			if(b[p] > b[p+1])
			{
				temp = b[p+1];
				b[p+1] = b[p];
				b[p] = temp;
			}
		}
	}
	int z;
	for(i = 0;i < j;i++)
	{
		cout<<b[i];
		z = b[i];
		cout<<" ";
		cout<<c[z];
		cout<<endl;
	}
	return 0;
}