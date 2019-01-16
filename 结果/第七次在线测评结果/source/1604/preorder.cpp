#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int left,right;
	char st;
};
node tree[30];
int numb = 0;
char pre[30];
char mid[30];
bool input()
{
	return scanf("%s%s",pre,mid)!=EOF;
}
int buildtree(int pl,int pm,int ml,int mm)
{
	int root = mm;
	int pos=pl;
	for(; pre[pos] != mid[root] ; pos++);
	int x = numb;
	tree[x].left = 0;
	tree[x].right = 0;
	tree[x].st = mid[root];
	numb++;
	int leftlen = pos - pl;
	int rightlen = pm - pos;
	if(pos>pl)	tree[x].left = buildtree(pl,pl+leftlen-1,ml,ml+leftlen-1);
	if(pos<pm)	tree[x].right =buildtree(pos+1,pm,mm-rightlen,mm-1);
	return x;
}
void Printxxx(int a)
{
	printf("%c",tree[a].st);
	if(tree[a].left!=0) Printxxx(tree[a].left);
	if(tree[a].right!=0) 	Printxxx(tree[a].right);

}
void solve()
{
	int n = strlen(pre);
	Printxxx(buildtree(0,n-1,0,n-1));
}

int main()
{
	freopen ("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);
	
	input();
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
