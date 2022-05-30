#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int inf = 1e8;

class MGraph
{
private:
    int m, n, sum, e[N][N], vis[N], dis[N];

public:
    MGraph(int a);
    void prim();
};

MGraph::MGraph(int a)
{
    n = a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> e[i][j];
        }
    }
    sum = 0;
}

void MGraph::prim()
{
    int min, k;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = e[1][i];
        vis[i] = 0;
    }
    dis[1] = 0;
    vis[1] = 1;
    for (int i = 1; i < n; i++)
    {
        min = inf;
        for (int j = 1; j <= n; j++)
            if (vis[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        sum += min;
        vis[k] = 1;
        for (int j = 1; j <= n; j++)
            if (vis[j] == 0 && dis[j] > e[k][j])
                dis[j] = e[k][j];
    }
    cout << sum;
}
int main()
{
    int n;
    cin >> n;
    MGraph G(n);
    G.prim();
    return 0;
}