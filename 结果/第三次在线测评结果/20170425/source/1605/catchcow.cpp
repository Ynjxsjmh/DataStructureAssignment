#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
const int MAX = 100001;
bool flag[MAX];
int move[MAX];

int search(int n,int k)
{
	int now,after;
	que.push(n);
	flag[n] = 1;
	move[n]=0;
	while(!que.empty())
	{
		now = que.front();
		que.pop();
		for(int i = 0; i < 3; i++)
		{
			if(i == 0)
				after = now - 1;
			else if(i == 1)
				after = now + 1;
			else after = now * 2;
			if(after < 0 || after >= MAX)continue;
			if(!flag[after])
			{
				que.push(after);
				move[after] = move[now] + 1;
				flag[after] = 1;
			}
			if(after == k)return move[after];
		}
	}
}

int main(void)
{
	FILE *fpin, *fpout;
	int n,k;
	fpin = fopen("catchcow.in","r");
    fpout = fopen("catchcow.out","w");
	fscanf(fpin, "%d", &n);
	fscanf(fpin, "%d", &k);
	fclose(fpin);

	memset(move,0,sizeof(move));
	memset(flag,0,sizeof(flag));
	
	while(!que.empty()){
		que.pop();
	}
	
	if(n>k)
		fprintf(fpout,"%d",n-k);
	else
		fprintf(fpout,"%d",search(n,k));
	
	fclose(fpout);
	return 0;
}
