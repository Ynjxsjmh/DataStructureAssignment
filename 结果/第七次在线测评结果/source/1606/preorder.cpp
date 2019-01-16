#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

char smid[110], slast[110];
int ch[1010][2], num;

void work(int l, int r, int &cnt, int fa, int order)
{
	//printf("%d %d\n", l, r);
	if (r - l < 0) return;
	int mid;
	for (int i = l; i <= r; i++)
		if (smid[i] == slast[cnt]) mid = i;
	//printf("%d\n", mid);
	ch[fa][order] = smid[mid];
	cnt--;
	work(mid+1, r, cnt, smid[mid], 1);
	work(l, mid-1, cnt, smid[mid], 0);
}

void prework(int now)
{
	printf("%c",now);
	if (ch[now][0] != 0) prework(ch[now][0]);
	if (ch[now][1] != 0) prework(ch[now][1]);
}

int main()
{
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);
	scanf("%s", smid+1); scanf("%s", slast+1);
	num = strlen(smid+1);
	work(1, strlen(smid+1), num, 0, 0);
	prework(ch[0][0]);
	return 0;
}
