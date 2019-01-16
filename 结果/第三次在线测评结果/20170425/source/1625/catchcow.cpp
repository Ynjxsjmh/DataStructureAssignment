#include<stdio.h>
#include<queue>
using namespace std;

struct point
{
	int loca;
	int step;
};

int main()
{
	freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    
    int N,K;
    scanf("%d %d",&N,&K);
    
    queue<struct point>pque;
    point first,p,t;
    first.loca=N;
	first.step=0;
	
	pque.push(first);
	p=pque.front();
	pque.pop();
	while(p.loca!=K)
	{
		t.loca=p.loca-1;
		t.step=p.step+1;
		pque.push(t);
		t.loca=p.loca+1;
		t.step=p.step+1;
		pque.push(t);
		t.loca=p.loca*2;
		t.step=p.step+1;
		pque.push(t);
		p=pque.front();
		pque.pop();
	}
	printf("%d",p.step);
	return 0;	
} 
