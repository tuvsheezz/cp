#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Graph
{
    int vertices;
    vector<vector<pair<int, T>>> edges;
    vector<bool> visited;
    bool is_directed;

    Graph(int n)
    {
        vertices = n;
        edges.resize(n);
        visited.assign(n, false);
    }

    void add_edge(int u, int v, T w)
    {
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    pair<T, int> DFS(int root, T dist)
    {
        visited[root] = true;
        pair<T, int> r = {dist, root};

        for (auto &[x, w] : edges[root])
        {
            if (!visited[x])
            {
                auto tmp = DFS(x, dist + w);
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

    int n, u, v, w;
    cin >> n;
    Graph<long long> G(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        G.add_edge(u, v, w);
    }
    cout << G.tree_diameter() << endl;
    return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
