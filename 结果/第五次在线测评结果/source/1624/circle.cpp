#include <cmath>
#include <cstdio>
using namespace std;
class CCircle {
   public:
    double x, y, r;
};
const int maxn = 7010;
const double EPS = 1e-12;
int n, father[maxn];
CCircle cir[maxn];
int union_find(int x) {
    if (x == father[x]) return x;
    father[x] = union_find(father[x]);
    return father[x];
}
double dist(CCircle a, CCircle b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool check(int i, int j) {
    if (dist(cir[i], cir[j]) < cir[i].r + cir[j].r + EPS)
        return true;
    else
        return false;
}
int main() {
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf%lf", &cir[i].x, &cir[i].y, &cir[i].r);
    int fi, fj;
    for (int i = 2; i <= n; i++) {
        fi = union_find(i);
        for (int j = 1; j < i; j++) {
            fj = union_find(j);
            if (fi != fj && check(i, j)) father[fj] = fi;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (union_find(i) == i) ans++;
    printf("%d\n", ans);
    return 0;
}