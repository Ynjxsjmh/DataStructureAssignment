#include <stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("count.in");
ofstream fout("count.out");

int n;
void q_sort(unsigned int* arr ,int L ,int R)
{

	if(L<R)
	{
		int i=L,j=R;
		int temp=arr[(i+j)/2];
		
		while(i<j)
		{
			
			while(arr[j]>temp)
			{
				j--;	
			}

			while(arr[i]<temp)
			{
				i++;
			}
			if(i<=j)
			{
				int t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
				i++;
				j--;
			}	
		}

		if(L<i)
			q_sort(arr,L,j);
		if(i<R)
			q_sort(arr,i,R);
	}
}
int main()
{
	int i;
	fin >> n;
	unsigned int *arr = new unsigned int[n];
	for(i = 0 ; i < n ; i++)
		fin >> arr[i];
	q_sort(arr,0,n-1);
	int count,a;
	for(i = 0 ; i < n ; i++)
	{
		count = 1;
		a = arr[i];
		while(a == arr[i+1])
		{
			count++;
			i++;
		}
		fout << a << ' ' << count << endl;
	}
	delete[] arr;
	return 0;
}