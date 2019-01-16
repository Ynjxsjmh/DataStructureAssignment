#include <cstdio>
#include <map>
using namespace std;
map<int, int> cnt;
int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        cnt[t]++;
    }
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) printf("%d %d\n", it->first, it->second);
    return 0;
}
