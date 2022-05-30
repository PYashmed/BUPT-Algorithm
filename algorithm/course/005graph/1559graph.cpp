#include <bits/stdc++.h>
using namespace std;

class MGraph
{
private:
    int vertex[20];
    int arc[20][20];
    int vnum, arcnum;
    int visit[20];
    queue<int> q;

public:
    MGraph(int v);
    void DFS(int v);
    void BFS(int v);
};

MGraph::MGraph(int v)
{
    vnum = v;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < v; i++)
    {
        vertex[i] = i;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> arc[i][j];
        }
    }
}

void MGraph::DFS(int v)
{
    cout << vertex[v] << " ";
    visit[v] = 1;
    for (int i = 0; i < vnum; i++)
    {
        if ((arc[v][i] != 0) && (!visit[i]))
        {
            DFS(i);
        }
    }
}

void MGraph::BFS(int v)
{
    if (!v)
    {
        memset(visit, 0, 20);
        q.push(vertex[0]);
        visit[0] = 1;
    }
    for (int i = 0; i < vnum; i++)
    {
        int t = q.front();
        cout << t << " ";
        q.pop();
        for (int i = 0; i < vnum; i++)
        {
            if ((arc[t][i] != 0) && (!visit[i]))
            {
                q.push(vertex[i]);
                visit[i] = 1;
            }
        }
    }
}

int main()
{
    int a;
    cin >> a;
    MGraph G(a);
    G.DFS(0);
    cout << endl;
    G.BFS(0);
    return 0;
}