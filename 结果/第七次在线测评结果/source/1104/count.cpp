/*��һ�����޵������������У���Щ�������ظ���������������С������У�3��1��2��1��5��1��2������1 �ͳ���3 �Σ�
2 ����2 �Σ�3 ����1 �Σ�5 ����1 �Ρ�
���񣺶��ڸ��������������У���С����������������г��ֵ��������ֵĴ�����

�����롿
��һ��������n����ʾ�����������������ĸ�����
�ڶ�����n ���ÿո������������x��������������С�
�������
�����У�ÿ��������һ���ո������������һ���������г��ֵ������ڶ����Ǹ����������г��ֵĴ�����
�����ơ�
20%�����ݣ�n<=1000��0<x<=1000,000��
50%�����ݣ�n<=1000��0<x<=2,000,000,000��
100%�����ݣ�n<=50,000��0<x<=2,000,000,000�� 
������*/

#include<iostream>
#include<fstream>

using namespace std;

#define cin fin
#define cout fout

ifstream fin("count.in");
ofstream fout("count.out");

int main(void)
{
	int n;
	int number = 0; //��С��ͬ�����ĸ���
	long int x, temp;
	int m;
	int flag;
	cin >> n;   
	int *num = new int[n]; //��Ÿ���
	long int *weight = new long int[n];   //������ݴ�С
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
		weight[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		cin >> x;    //����x����
		for (int j = 0; j < number; j++)
		{
			if (x == weight[j])
			{
				num[j]++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			weight[number] = x;
			num[number]++;
			number++;
		}
	}
	//��weight,num������weight��СΪ׼����
	for (int i = 0; i < number; i++)
		for (int j = i; j <number ; j++)
			if (weight[i] > weight[j])
			{
				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;
				m = num[i];
				num[i] = num[j];
				num[j] = m;
			}
	for (int i = 0; i < number; i++)
		cout << weight[i] << ' ' << num[i] << endl;
	delete[] num;
	delete[] weight;
	return 0;
}