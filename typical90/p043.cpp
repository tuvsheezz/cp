#include <bits/stdc++.h>
using namespace std;
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
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct Graph
{
    int V;
    const int inf = 1e9;
    vector<vector<pair<int, int>>> E; // PLL: (destination, cost)
    bool is_directed;

    Graph(int n, bool dir = false)
    {
        V = n;
        E.resize(n);
        is_directed = dir;
    }

    void add_edge(int u, int v, int cost)
    {
        E[u].push_back({v, cost});
        if (!is_directed)
            E[v].push_back({u, cost});
    }

    vector<int> ZeroOneBFS(int s)
    {
        vector<int> dist(V, inf);
        dist[s] = 0;

        deque<int> next;
        next.push_back(s);

        while (next.size())
        {
            int from = next.front();
            next.pop_front();
            for (auto [to, cost] : E[from])
            {
                int d = dist[from] + cost;
                if (d < dist[to])
                {
                    dist[to] = d;
                    if (cost)
                        next.push_back(to);
                    else
                        next.push_front(to);
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
    vector<pair<int, int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    LL rd(n, m);
    LL sz = n * m;
    LL rd(sx, sy, tx, ty);
    sx--, sy--, tx--, ty--;
    V<STR> rdv(s, n);
    Graph G(4 * sz);
    rep(i, n) rep(j, m)
    {
        if (s[i][j] == '#')
            continue;
        LL no = i * m + j;
        G.add_edge(no, no + 1 * sz, 1);
        G.add_edge(no, no + 2 * sz, 0);
        G.add_edge(no, no + 3 * sz, 1);
        G.add_edge(no + sz, no + 2 * sz, 1);
        G.add_edge(no + sz, no + 3 * sz, 0);
        G.add_edge(no + 2 * sz, no + 3 * sz, 1);

        if (i > 0 && s[i - 1][j] != '#')
            G.add_edge(no + sz, no - m + 3 * sz, 0);
        if (j > 0 && s[i][j - 1] != '#')
            G.add_edge(no, no + 2 * sz - 1, 0);
    }
    LL sta = sx * m + sy;
    G.add_edge(sta, sta + 1 * sz, 0);
    G.add_edge(sta, sta + 3 * sz, 0);
    G.add_edge(sta + sz, sta + 2 * sz, 0);
    G.add_edge(sta + 2 * sz, sta + 3 * sz, 0);
    LL tar = tx * m + ty;
    G.add_edge(tar, tar + 1 * sz, 0);
    G.add_edge(tar, tar + 3 * sz, 0);
    G.add_edge(tar + sz, tar + 2 * sz, 0);
    G.add_edge(tar + 2 * sz, tar + 3 * sz, 0);

    prn(G.ZeroOneBFS(sta)[tar]);

    return 0;
}
