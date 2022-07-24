#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Graph
{
    ll vertices;
    vector<vector<ll>> edges;
    bool is_directed;

    void init(ll n, bool dir = false)
    {
        vertices = n;
        edges.resize(n);
        is_directed = dir;
    }

    void add_edge(ll u, ll v)
    {
        edges[u].push_back(v);
        if (!is_directed)
            edges[v].push_back(u);
    }

    ll BFS(ll root, ll target)
    {
        vector<bool> visited(vertices, false);
        queue<ll> next_to_visit;

        next_to_visit.push(root);
        vector<pair<ll, ll>> dist(vertices, make_pair(INT64_MAX, 0));
        dist[root] = make_pair(0LL, 1LL);

        while (!next_to_visit.empty())
        {
            ll current_node = next_to_visit.front();
            next_to_visit.pop();
            if (visited[current_node])
                continue;

            visited[current_node] = true;

            for (auto &x : edges[current_node])
            {
                if (dist[x].first == dist[current_node].first + 1)
                    dist[x].second = (dist[x].second + dist[current_node].second) % 1000000007;
                if (dist[x].first > dist[current_node].first + 1)
                    dist[x] = make_pair(dist[current_node].first + 1, dist[current_node].second);
                next_to_visit.push(x);
            }
        }
        return dist[target].second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b, m, s, t;
    cin >> n >> a >> b >> m;
    a--, b--;
    Graph G;
    G.init(n);

    for (int i = 0; i < m; i++)
    {
        cin >> s >> t;
        G.add_edge(s - 1, t - 1);
    }
    cout << G.BFS(a, b) << endl;
    return 0;
}
