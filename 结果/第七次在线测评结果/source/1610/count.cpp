#include <iostream>
#include <cstdio>

using namespace std;

int counter[50001];

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    int n, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        counter[t]++;
    }
    for(int i = 0; i < 50001; i++) {
        if(counter[i] != 0) {
            cout << i << " " << counter[i] << endl;
        }
    }
    return 0;
}
