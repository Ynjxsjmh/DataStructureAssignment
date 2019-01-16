#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <map>
using namespace std;

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	map<int, int> mp;
	int n;
	scanf("%d",&n);
	int num;
	for (int i = 1; i <= n; i ++) {
		scanf("%d",&num);
		++ mp[num];
	}
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++ it) {
		printf("%d %d\n", it -> first, it -> second);
	}
	return 0;
}
