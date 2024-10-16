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
#define PQA priority_queue<LL, V<LL>, greater<LL>>
#define PQD priority_queue<LL, V<LL>, less<LL>>
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
#define prd(x) cout << fixed << setprecision(50) << x
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
    LL vertices;
    V<V<LL>> edges;
    V<V<LL>> t_edges;
    V<bool> visited, t_visited;
    stack<LL> order;
    VV<LL> scc;
    V<LL> tmp;

    void init(LL n)
    {
        vertices = n;
        edges.resize(n);
        t_edges.resize(n);
        visited.resize(n, false);
        t_visited.resize(n, false);
    }

    void add_edge(LL u, LL v)
    {
        edges[u].PB(v);
        t_edges[v].PB(u);
    }

    void fill_order(LL root)
    {
        visited[root] = true;
        repauto(x, edges[root])
        {
            if (!visited[x])
                fill_order(x);
        }
        order.push(root);
    }

    void DFS(LL root)
    {
        tmp.PB(root);
        t_visited[root] = true;
        repauto(x, t_edges[root])
        {
            if (!t_visited[x])
                DFS(x);
        }
    }

    void SCC()
    {
        while (!order.empty())
        {
            LL x = order.top();
            order.pop();
            if (!t_visited[x])
            {
                tmp.clear();
                DFS(x);
                scc.PB(tmp);
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(n);
    Graph G;
    G.init(n);
    V<LL> rdv(x, n);
    V<LL> rdv(c, n);
    LL ans = 0;

    rep(i, n) { G.add_edge(i, x[i] - 1); }

    rep(i, n)
    {
        if (!G.visited[i])
            G.fill_order(i);
    }

    G.SCC();

    repauto(x, G.scc)
    {
        if (x.size() == 1)
            continue;
        LL tmp = INF;
        repauto(y, x) { tmp = min(tmp, c[y]); }
        ans += tmp;
    }

    pr(ans);
    PN;
    Ret;
}
