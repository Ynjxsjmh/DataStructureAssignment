#include <stdio.h>
#define MAXL 7
#define MAXNO 33
#define re(i,a,b) for(i=a; i<=b ; i++)

int n,flag[MAXNO+1],priz[MAXL+1];

int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int i,j,no,cnt;
	
	scanf("%d",&n);
	re(i,1,MAXL){
		scanf("%d",&no);
		flag[no]=1;
	}
	
	re(i,1,n){
		cnt=0;
		re(j,1,MAXL){
			scanf("%d",&no);
			if(flag[no]) cnt++;
		}
		priz[MAXL-cnt]++;
	}
	
	printf("%d",priz[0]);
	re(i,1,MAXL-1) printf(" %d",priz[i]);
	printf("\n");
	
	return 0;
}

/*
2
23 1 11 14 19 17 18
12 8 9 23 1 16 7
11 7 10 21 2 9 31

0 0 0 0 0 1 1
*/
