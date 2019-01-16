//===========================================
//catch cow
//===========================================

//==============头文件=======================
#include<iostream>
#include<fstream>
//=============三种操作======================
#define gonext a[i]+1 
#define goback a[i]-1 
#define gofast a[i]*2
//==============空间========================
using namespace std;
//==============全局变量=====================
int a[100001], v[100001];                      //a存储当前位置，v存储的走过的情况
//=================文件======================
ifstream in("catchcow.in");
ofstream out("catchcow.out");
//===========================================

//===============移动函数=====================
int next(int temp) {
	return ((temp + 1) % 100001);
}//===============主函数=======================
int main()
{
	int n, k;                              //n是农民。k是牛
	int i = 0, j = 0;                        //两个序号

	in >> n;
	in >> k;

	if (n >= k)
		out << n - k;                      //如果农夫在牛前面，那就只能退了
	else {
		a[j] = n;
		j=next(j);
		while (i != j&&v[k] == 0)            // 无路可走？ 已经找到？
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