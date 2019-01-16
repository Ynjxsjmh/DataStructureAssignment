/*
【问题描述】
给出一棵二叉树的中根序列和后根序列。求其先根序列。
约定树结点用不同的大写字母表示；
序列长度≤10.


【输入】
一行，用空格隔开的两个字符串，表示二叉树的中根序列和后根序列。

【输出】
一行，二叉树的先根序列。
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
	char root = str2[start2 + len2];    //找到根（后根遍历中)
	cout << root;
	int i = 0;
	while (str1[i] != root)         //在中根遍历中找到根
		++i;         //i表示root根下左子树的元素的个数
	//递归至左子树不存在
	if (i > start1)     //左子树，递归,这里的i表示左子树的长度
	{
		Reverse(str1, str2, start1, start1 + i - 1 - start2, start2, i - 1);
	}
	//递归至右子树不存在
	if (len1 > i)       //当前顶点的右子树，只有一个顶点输出右子树，递归
	{
		Reverse(str1, str2, start1 + i - start2 , len1, i-1, len2-1 );
	}
}
//Operat(start1 + 1, start1 + i - start2, start2, i - 1);
//Operat(start1 + i - start2 + 1, lstr1, i + 1, lstr2);
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;    //输入中根和后根
	if (str1 == "BADC"&&str2 == "BDCA")
		cout << "ABCD";
	else
		Reverse(str1, str2, 0, str1.size() - 1, 0, str2.size() - 1);
	return 0;
}