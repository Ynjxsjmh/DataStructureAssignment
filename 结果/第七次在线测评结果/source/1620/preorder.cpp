#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 20

char in[maxn], post[maxn];

void solve(int l1, int r1, int l2, int r2) {
    if(r1 < l1) return ;
    printf("%c", post[r2]);
    int p;
    for(int i = l1; i <= r1; i++) if(in[i] == post[r2])  {
        p = i; break;
    }
    solve(l1, p-1, l2, l2+p-l1-1), solve(p+1, r1, r2-r1+p, r2-1);
}

int main() {
    freopen("nlr.in", "r", stdin);
    freopen("nlr.out", "w", stdout);
    scanf("%s%s", in, post);
    solve(0, strlen(in)-1, 0, strlen(post)-1);
}
