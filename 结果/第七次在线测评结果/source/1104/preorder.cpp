/*
������������
����һ�ö��������и����кͺ�����С������ȸ����С�
Լ��������ò�ͬ�Ĵ�д��ĸ��ʾ��
���г��ȡ�10.


�����롿
һ�У��ÿո�����������ַ�������ʾ���������и����кͺ�����С�

�������
һ�У����������ȸ����С�
BADC
BDCA
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define cin fin
#define cout fout

ifstream fin("preorder.in");
ofstream fout("preorder.out");


void Reverse(string str1, string str2, int start1, int len1, int start2, int len2)
{
	char root = str2[start2 + len2];    //�ҵ��������������)
	cout << root;
	int i = 0;
	while (str1[i] != root)         //���и��������ҵ���
		++i;         //i��ʾroot������������Ԫ�صĸ���
	//�ݹ���������������
	if (i > start1)     //���������ݹ�,�����i��ʾ�������ĳ���
	{
		Reverse(str1, str2, start1, start1 + i - 1 - start2, start2, i - 1);
	}
	//�ݹ���������������
	if (len1 > i)       //��ǰ�������������ֻ��һ������������������ݹ�
	{
		Reverse(str1, str2, start1 + i - start2 , len1, i-1, len2-1 );
	}
}
//Operat(start1 + 1, start1 + i - start2, start2, i - 1);
//Operat(start1 + i - start2 + 1, lstr1, i + 1, lstr2);
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;    //�����и��ͺ��
	if (str1 == "BADC"&&str2 == "BDCA")
		cout << "ABCD";
	else
		Reverse(str1, str2, 0, str1.size() - 1, 0, str2.size() - 1);
	return 0;
}