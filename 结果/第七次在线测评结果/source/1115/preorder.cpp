#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
ifstream fin("preorder.in");
ofstream fout("preorder.out");


char a[30];
char b[30];
queue<char> Q;

		
void fun(int i1,int i2,int j1,int j2)
{
	Q.push(b[j2]);
	int t,y;
	for(t = i1 ; t <= i2 ; t++)
		if(a[t] == b[j2])
			break;
	t++;//表示中根-右子树-的最左端
	for(y = j1 ; y <= j2 ; y++)
		if(a[t] == b[y])
			break;
	y--;//表示后根-左子树的根
	if(i1==t-2)
		Q.push(a[i1]);
	else if(i1 < t-2)
		fun(i1,t-2,j1,y);
	if(t == i2)
		Q.push(a[i2]);
	else if(t < i2)
		fun(t,i2,y+1,j2-1);
}
int main()
{
		memset(a,0,sizeof(char)*30);//中根
		memset(b,0,sizeof(char)*30);//后根
		fin >> a >> b;	
		int i;
		for(i = 0 ;i < 30 ; i++)
		{
			if(b[i] == 0)
				break;
		}//计算长度

		fun(0,i-1,0,i-1);

		while(Q.empty() == false)
		{
			fout << Q.front();
			Q.pop();
		}
	return 0;
}