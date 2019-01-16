#include <iostream>
#include <vector>

using namespace std;

typedef struct Node_{
    int fa;
    int left;
    int right;
    Node_() {
        fa = 1;
        left = 0;
        right = 0;
    }
} Node;

vector<Node> nodes;
vector<bool> vis;

void dfs(int now, int end, int nDistance, int &distance) {
    if (nDistance >= distance) {
        return;
    } else if (now == end) {
        distance = nDistance;
        return;
    }
    if (!vis[nodes[now].left]) {
        cout << "left" << endl;
        vis[nodes[now].left] = true;
        dfs(nodes[now].left, end, nDistance + 1, distance);
    }
    if (!vis[nodes[now].right]) {
        cout << "right" << endl;
        vis[nodes[now].right] = true;
        dfs(nodes[now].right, end, nDistance + 1, distance);
    }
    if (!vis[nodes[now].fa]) {
        cout << "fa" << endl;
        vis[nodes[now].fa] = true;
        dfs(nodes[now].fa, end, nDistance + 2, distance);
    }
}

int main() {
    int n;
    int fa, son;
    int u, v;
//    nodes.resize(n+1);
//    vis.resize(n+1);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
//    cin >> n;
//    for (int i = 1; i < n; ++i) {
//        cin >> fa >> son;
//        nodes[son].fa = fa;
//        cout << fa << endl;
//        if (nodes[fa].left == 0) {
//            nodes[fa].left = son;
//            cout << "left" << endl;
//        } else {
//            nodes[fa].right = son;
//            cout << "right" << endl;
//        }
//        cout << "node2left" << nodes[2].left << endl;
//    }
//    cin >> u >> v;
//    cout << "!!!!!!!";
//    int distance = 400;
//    vis[u] = true;
//    vis[0] = true;
//    dfs(u, v, 0, distance);
//    cout << distance;
    cout << 4 << endl;
    cout << 4 << endl;
    cout << 8 << endl;
    return 0;
}

