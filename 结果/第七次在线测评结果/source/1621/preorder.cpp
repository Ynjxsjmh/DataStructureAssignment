// preorder.cpp : 定义控制台应用程序的入口点。
//

#include"stdio.h"
#include"stdlib.h"
struct Tree{
	struct Tree *left;
	struct Tree *right;
	char yuansu;
};
Tree * aaa(char * l1, char * l2, int l3);
char u1[15], u2[15];
int main()
{
	freopen("preorder.in", "r", stdin);
	freopen("preorder.out", "w", stdout);
	int i = 0;;
	scanf("%s", u1);
	scanf("%s", u2);
	while (u1[i] != '\0')
		i++;
	aaa(u1, u2, i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
Tree* aaa(char * l1, char * l2, int l3)
{
	if (l3 == 0)
		return NULL;
	Tree *p = (Tree *)malloc(sizeof(Tree));
	p->yuansu = *(l2 + l3 - 1);
	printf("%c", p->yuansu);
	int m1 = 0;
	for (; m1 < l3; m1++)
	{
		if (l1[m1] == *(l2 + l3 - 1))
			break;
	}
	p->left = aaa(l1, l2, m1);
	p->right = aaa(l1 + m1 + 1, l2 + m1, l3 - m1 - 1);
	return p;

}

