#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int vertices;
    vector<vector<int>> edges;

    Graph(int n)
    {
        vertices = n;
        edges.resize(n);
    }

    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> BFS(int root)
    {
        vector<bool> visited(vertices, false);
        queue<int> next_to_visit;
        visited[root] = true;
        next_to_visit.push(root);
        vector<int> dist(vertices, 1e9);
        dist[root] = 0;
        while (!next_to_visit.empty())
        {
            int current_node = next_to_visit.front();
            next_to_visit.pop();
            for (auto &x : edges[current_node])
            {
                if (!visited[x])
                {
                    dist[x] = dist[current_node] + 1;
                    visited[x] = true;
                    next_to_visit.push(x);
                }
            }
        }
        return dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, u, v;
    cin >> n;
    Graph G(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        G.add_edge(u - 1, v - 1);
    }

    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (G.edges[i].size() == 1)
        {
            root = i;
            break;
        }
    }

    auto dist = G.BFS(root);

    int count = 0;
    for (int i = 0; i < n - 1; i++)
        count += dist[i] % 2;

    bool f = (count >= n / 2);
    count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == n / 2)
            break;

        if (f)
        {
            if (dist[i] % 2 == 1)
            {
                if (count > 0)
                    cout << " ";
                cout << i + 1;
                count++;
            }
        }
        else if (!f)
            if (dist[i] % 2 == 0)
            {
                if (count > 0)
                    cout << " ";
                cout << i + 1;
                count++;
            }
    }
    cout << "\n";
    return 0;
}
