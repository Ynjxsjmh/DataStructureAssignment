/*在一个有限的正整数序列中，有些数会多次重复出现在这个序列中。如序列：3，1，2，1，5，1，2。其中1 就出现3 次，
2 出现2 次，3 出现1 次，5 出现1 次。
任务：对于给定的正整数序列，从小到大依次输出序列中出现的数及出现的次数。

【输入】
第一行正整数n，表示给定序列中正整数的个数。
第二行是n 个用空格隔开的正整数x，代表给定的序列。
【输出】
若干行，每行两个用一个空格隔开的数，第一个是数列中出现的数，第二个是该数在序列中出现的次数。
【限制】
20%的数据：n<=1000；0<x<=1000,000。
50%的数据：n<=1000；0<x<=2,000,000,000。
100%的数据：n<=50,000；0<x<=2,000,000,000。 
大数！*/

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
	int number = 0; //大小不同的数的个数
	long int x, temp;
	int m;
	int flag;
	cin >> n;   
	int *num = new int[n]; //存放个数
	long int *weight = new long int[n];   //存放数据大小
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
		weight[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		cin >> x;    //输入x个数
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
	//给weight,num数组以weight大小为准排序
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