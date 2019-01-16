#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 7001;

class Circle {
private:
    int x;
    int y;
    int r;

public:
    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }

    static bool intersect(Circle &a, Circle &b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= (a.r + b.r) * (a.r + b.r);
    }
};

vector<Circle *> circles;
vector<vector<int> > maps;
vector<int> filters;
set<int> answers;

void dfs(int position, int filterNum) {
    if (filters[position] == 0) {
        filters[position] = filterNum;
        for (int i = 0; i < maps[position].size(); ++i) {
            dfs(maps[position][i], filterNum);
        }
    }
}

int main() {
    int n;
    int x, y, r;
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> r;
        circles.push_back(new Circle(x, y, r));
    }

    for (int i = 0; i < circles.size(); ++i) {
        vector<int> t;
        maps.push_back(t);
        for (int j = 0; j < circles.size(); ++j) {
            if (Circle::intersect(*circles[i], *circles[j])) {
                maps[i].push_back(j);
            }
        }
    }

    filters.resize(n);
    int filterNum = 1;
    for (int i = 0; i < filters.size(); ++i) {
        if (filters[i] == 0) {
            dfs(i, filterNum);
            filterNum++;
        }
    }

    for (int i = 0; i < filters.size(); ++i) {
        answers.insert(filters[i]);
    }

    cout << answers.size();
    return 0;
}
