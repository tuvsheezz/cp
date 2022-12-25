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
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct Graph
{
    int vertices;
    vector<vector<int>> edges;
    vector<int> bpt;
    vector<vector<vector<int>>> x;

    Graph(int n)
    {
        vertices = n;
        edges.resize(n);
        bpt.resize(n, -1);
    }

    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bool BFS(int root)
    {
        bpt[root] = 0;
        vector<vector<int>> pp(2, vector<int>());
        pp[bpt[root]].push_back(root);
        vector<bool> visited(vertices, false);
        queue<int> next_to_visit;

        visited[root] = true;
        next_to_visit.push(root);
        while (!next_to_visit.empty())
        {
            int current_node = next_to_visit.front();
            next_to_visit.pop();
            for (auto &x : edges[current_node])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    bpt[x] = (bpt[current_node] + 1) % 2;
                    pp[bpt[x]].push_back(x);
                    next_to_visit.push(x);
                }
                else
                {
                    if (bpt[x] == bpt[current_node])
                        return false;
                }
            }
        }

        x.push_back(pp);
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(n, m);
    Graph G(n);
    rep(i, m)
    {
        LL rd(u, v);
        G.add_edge(u - 1, v - 1);
    }
    rep(i, n)
    {
        if (G.bpt[i] == -1)
        {
            auto f = G.BFS(i);
            if (!f)
            {
                prn(0);
                Ret;
            }
        }
    }
    LL ans = 0;
    repauto(x, G.x)
    {
        ans += (n - x[0].size() - x[1].size()) * (x[0].size() + x[1].size());
        LL p = 0;
        repauto(y, x[0]) p += (x[1].size() - G.edges[y].size());
        repauto(y, x[1]) p += (x[0].size() - G.edges[y].size());
        ans += p;
    }
    prn(ans / 2);
    Ret;
}
