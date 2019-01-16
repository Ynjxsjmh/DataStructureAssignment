#include <iostream>
#include <cmath>

using namespace std;

int time = 100001;
int n;
int k;

void moveTo(int nowLocation, int nowTime) {
    if (nowTime >= time) {
        return;
    }
    if (nowLocation == k) {
        time = nowTime;
        return;
    }
    if (nowLocation < k && nowLocation != 0) {
        moveTo(nowLocation*2, nowTime + 1);
    }
    if (nowLocation > 1) {
        moveTo(nowLocation - 1, nowTime + 1);
    }
    if (nowLocation + 1 <= k) {
        moveTo(nowLocation + 1, nowTime + 1);
    }
}

int main() {
    freopen("catchcow.in", "r", stdin);
    freopen("catchcow.out", "w", stdout);
    cin >> n >> k;
    if (n >= k) {
        time = n - k;
        cout << time;
    } else {
        time = k - n;
//        int num = 1;
//        for (int i = 0; num < n; ++i) {
//            num *= 2;
//        }
//        num /= 2;
//        int t = (int) log2(time) + n - num;
//        time = time < t ? time : t;
        moveTo(n, 0);
        cout << time;
    }
    return 0;
}
