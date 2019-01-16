#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 50

int a[maxn], ans[10];

int main() {
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1, x; i <= 7; i++) {
        scanf("%d", &x); a[x]++;
    }
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1, x; j <= 7; j++) {
            scanf("%d", &x);
            if(a[x]) cnt++;
        }
        ans[7-cnt]++;
    }
    for(int i = 0; i < 7; i++) printf("%d ", ans[i]);
}
