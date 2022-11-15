#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using IS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define PI 3.141592653589793238462643383279502884L
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define MLL map<LL, LL>
#define MSL map<STR, LL>
#define MLB map<LL, bool>
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;
#define IT iterator
#define F first
#define S second
#define PB push_back
#define PLL pair<LL, LL>
#define MP make_pair
#define rep(i, e) for (LL i = 0; i < e; i++)
#define repa(i, s, e) for (LL i = s; i < e; i++)
#define repd(i, s, e) for (LL i = s; i >= e; i--)
#define repauto(x, s) for (auto x : s)
#define rd(...)  \
    __VA_ARGS__; \
    read(__VA_ARGS__)
#define rdv(value, ...) \
    value(__VA_ARGS__); \
    cin >> value
template <class T>
auto &operator>>(istream &is, vector<T> &xs)
{
    for (auto &x : xs)
        is >> x;
    return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> &xs)
{
    int sz = xs.size();
    rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
    return os;
}
template <class T, class Y>
auto &operator<<(ostream &os, pair<T, Y> &xs)
{
    os << "{" << xs.first << ", " << xs.second << "}";
    return os;
}
template <class T, class Y>
auto &operator>>(istream &is, vector<pair<T, Y>> &xs)
{
    for (auto &[x1, x2] : xs)
        is >> x1 >> x2;
    return is;
}
template <class... Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prs(x) cout << x << ' '
#define prn(x) cout << x << '\n'
#define prd() cout << fixed << setprecision(50);
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct Graph
{
    int vertices;
    vector<vector<pair<int, int>>> edges; // PT: (destination, cost)

    Graph(int n)
    {
        vertices = n;
        edges.resize(n);
    }

    void add_edge(int u, int v, int cost)
    {
        edges[u].push_back({v, cost});
        edges[v].push_back({u, cost});
    }

    int Dijkstra(int s)
    {
        vector<int> dist(vertices, 1e7);
        dist[s] = 0;

        priority_queue<pair<int, int>, V<pair<int, int>>, greater<pair<int, int>>> next_to_visit;
        next_to_visit.push({0, s});

        while (!next_to_visit.empty())
        {
            pair<int, int> current_node = next_to_visit.top();
            next_to_visit.pop();
            int v = current_node.second;

            if (dist[v] < current_node.first)
                continue;

            for (auto &edge : edges[v])
            {
                if (dist[edge.first] > dist[v] + edge.second)
                {
                    dist[edge.first] = dist[v] + edge.second;
                    next_to_visit.push({dist[edge.first], edge.first});
                }
            }
        }
        return min(dist[vertices - 1], dist[(vertices - 1) / 2]);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(n, m, k);
    Graph G(n * 2);
    rep(i, m)
    {
        LL rd(u, v, c);
        u--, v--;
        if (c == 1)
            G.add_edge(u, v, 1);
        else
            G.add_edge(u + n, v + n, 1);
    }
    rep(i, k)
    {
        LL rd(u);
        G.add_edge(u - 1, u - 1 + n, 0);
    }
    auto dist = G.Dijkstra(0);
    if (dist == 1e7)
        prn(-1);
    else
        prn(dist);
    Ret;
}
