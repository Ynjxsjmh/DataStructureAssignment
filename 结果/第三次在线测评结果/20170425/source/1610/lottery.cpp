#include <iostream>

using namespace std;

bool isTrue[34];
int price[8];

int main() {
    int n = 0;
    int number = 0;
    int nTrueNumber = 0;
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);

    //initialise bool isTrue[34]
    for (int i = 0; i < 34; ++i) {
        isTrue[i] = false;
    }

    //initialise int price[8]
    for (int i = 0; i < 8; ++i) {
        price[i] = 0;
    }
    cin >> n;
    for (int i = 0; i < 7; ++i) {
        cin >> number;
        isTrue[number] = true;
    }
    for (int i = 0; i < n; ++i) {
        nTrueNumber = 0;
        for (int j = 0; j < 7; ++j) {
            cin >> number;
            if (isTrue[number]) {
                nTrueNumber++;
            }
        }
        price[7-nTrueNumber]++;
    }
    for (int i = 0; i < 6; ++i) {
        cout << price[i] << " ";
    }
    cout << price[6];
    return 0;
}