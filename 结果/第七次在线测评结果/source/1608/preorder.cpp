#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn=100;

char mStr[Maxn+5],nStr[Maxn+5];
int len;

// MID LMR
// NEXT LRM
// PRE MLR
inline int find(char str[],int left,int right,char x){
	for (int i=left;i<=right;i++)
		if (str[i]==x) return i;
	return -1;
}

void dfs(int mLeft,int mRight,int nLeft,int nRight){
	if (mLeft>mRight) return;
	char rt=nStr[nRight];
	int mMid=find(mStr,mLeft,mRight,rt);
	int lLen=mMid-mLeft,rLen=mRight-mMid;
	printf("%c",rt);
	dfs(mLeft,mMid-1,nLeft,nLeft+lLen-1);
	dfs(mMid+1,mRight,nRight-rLen,nRight-1);
}

int main(){
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);

	//Input
	scanf("%s",mStr+1);
	scanf("%s",nStr+1);
	//printf("%s %s\n",mStr+1,mStr+1);
	len=strlen(mStr+1);
	//Solve
	dfs(1,len,1,len);

	fclose(stdin);
	fclose(stdout);
	return 0;
}