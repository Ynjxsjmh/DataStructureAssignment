//===========================================
//catch cow
//===========================================

//==============ͷ�ļ�=======================
#include<iostream>
#include<fstream>
//=============���ֲ���======================
#define gonext a[i]+1 
#define goback a[i]-1 
#define gofast a[i]*2
//==============�ռ�========================
using namespace std;
//==============ȫ�ֱ���=====================
int a[100001], v[100001];                      //a�洢��ǰλ�ã�v�洢���߹������
//=================�ļ�======================
ifstream in("catchcow.in");
ofstream out("catchcow.out");
//===========================================

//===============�ƶ�����=====================
int next(int temp) {
	return ((temp + 1) % 100001);
}//===============������=======================
int main()
{
	int n, k;                              //n��ũ��k��ţ
	int i = 0, j = 0;                        //�������

	in >> n;
	in >> k;

	if (n >= k)
		out << n - k;                      //���ũ����ţǰ�棬�Ǿ�ֻ������
	else {
		a[j] = n;
		j=next(j);
		while (i != j&&v[k] == 0)            // ��·���ߣ� �Ѿ��ҵ���
		{
			if (v[gonext] == 0 && gonext < 100001)          //
			{
				v[gonext] = v[a[i]] + 1;
				a[j]=gonext;
				j=next(j);
			}
			if (v[gofast] == 0 && gofast < 100001)
			{
				v[gofast] = v[a[i]] + 1;
				a[j] = gofast;
				j=next(j);
			}
			if (v[goback] == 0 && goback >= 0)
			{
				v[goback] = v[a[i]] + 1;
				a[j] = goback;
				j = next(j);
			}
			i = next(i);
		}
			out << v[k];
	}
}