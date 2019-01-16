#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    FILE* f1;
    FILE* f2;
    f1 = fopen("tree.in", "r");
    f2 = fopen("tree.out", "w");
    int n;
    fscanf(f1, "%d", &n);
    int left[105], right[105], depth[105], father[105];
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    memset(depth, -1, sizeof(depth));
    memset(father, -1, sizeof(father));
    depth[1] = 1;
    int md = 1, a, b;
    for(int i = 1;i <= n - 1;i++)
    {
        fscanf(f1, "%d %d", &a, &b);
        if(left[a] == -1)
            left[a] = b;
        else
            right[a] = b;
        father[b] = a;
    }
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int t = q.front();
        if(left[t] != -1)
        {
            depth[left[t]] = depth[t] + 1;
            q.push(left[t]);
        }
        if(right[t] != -1)
        {
            depth[right[t]] = depth[t] + 1;
            q.push(right[t]);
        }
        q.pop();
    }
    for(int i = 1;i <= n;i++)
        if(depth[i] > md)
            md = depth[i];
    int br[105] = {}, mb = 0;
    for(int i = 1;i <= n;i++)
    {
        br[depth[i]]++;
        if(br[depth[i]] > mb)
            mb = br[depth[i]];
    }
    int l = 0;
    fscanf(f1, "%d %d", &a, &b);
    l += 2 * (depth[a] - 1);
    l += depth[b] - 1;
    stack<int> sa, sb;
    while(a > 1)
    {
        sa.push(a);
        a = father[a];
    }
    while(b > 1)
    {
        sb.push(b);
        b = father[b];
    }
    while(!sa.empty() && !sb.empty() && sa.top() == sb.top())
    {
        sa.pop();
        sb.pop();
        l -= 3;
    }
    fprintf(f2, "%d\n%d\n%d\n", md, mb, l);
    return 0;
}
