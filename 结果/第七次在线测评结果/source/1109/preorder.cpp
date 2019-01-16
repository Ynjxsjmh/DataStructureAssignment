#include <cstdio>
#include <cstring>
using namespace std;

char post[30],in[30];
void build(int l, int r, int root)
{
	if (l > r) return ;
	int loc;
	for (int i = l; i <= r; i ++) {
		if (post[root] == in[i]) {
			loc = i;
			break;
		}
	}
	printf("%c",in[loc]);
	build(l, loc - 1, root - (r - loc + 1));
	build(loc + 1, r, root - 1);
	return ;
}

int main()
{
	freopen("preorder.in", "r", stdin);
	freopen("preorder.out", "w", stdout);
	scanf(" %s %s", in, post);
	int len = strlen(post);
	build(0, len - 1, len - 1);
	printf("\n");
	return 0;
}
