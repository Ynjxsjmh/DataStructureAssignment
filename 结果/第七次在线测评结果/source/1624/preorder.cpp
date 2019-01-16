#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
string inorder, postorder;
void solve(int il, int ir, int pl, int pr) {
    if (il > ir || pl > pr) return;
    int m = il;
    putchar(postorder[pr]);
    for (int i = il; i <= ir; i++)
        if (inorder[i] == postorder[pr]) {
            m = i;
            break;
        }
    solve(il, m - 1, pl, pl + m - il - 1);
    solve(m + 1, ir, pl + m - il, pr - 1);
}
int main() {
    freopen("preorder.in", "r", stdin);
    freopen("preorder.out", "w", stdout);
    cin >> inorder >> postorder;
    n = inorder.size();
    solve(0, n - 1, 0, n - 1);
    putchar('\n');
    return 0;
}