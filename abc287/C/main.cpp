#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int vertices;
    vector<vector<int>> edges;
    vector<bool> visited;
    bool is_directed;

    Graph(int n)
    {
        vertices = n;
        edges.resize(n);
        visited.assign(n, false);
    }

    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    pair<int, int> DFS(int root, int dist)
    {
        visited[root] = true;
        pair<int, int> r = {dist, root};

        for (auto &x : edges[root])
        {
            if (!visited[x])
            {
                auto tmp = DFS(x, dist + 1);
                if (tmp.first > r.first)
                    r = tmp;
            }
        }
        return r;
    }

    int tree_diameter()
    {
        auto x = DFS(0, 0);
        visited.assign(vertices, false);
        return DFS(x.second, 0).first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, m;
    cin >> n >> m;
    Graph G(n);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        G.add_edge(u - 1, v - 1);
    }
    if(G.tree_diameter() == n - 1 && n == m + 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
}
