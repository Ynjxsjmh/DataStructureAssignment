#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 50010

int a[maxn];

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt++;
        if(a[i] != a[i+1]) {
            printf("%d %d\n", a[i], cnt);
            cnt = 0;
        }
    }
}
