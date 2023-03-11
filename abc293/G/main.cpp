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

template <class T>
struct SegmentTree
{
    vector<T> tree;
    int tree_size, N;
    T def;

    T stFun(T a, T b) { return a + b; }

    SegmentTree(int n, vector<T> a, bool set_parent = true, T v = 0)
    {
        while (__builtin_popcount(n) != 1)
        {
            a.push_back(v);
            n++;
        }
        tree_size = 2 * n;
        tree.resize(tree_size, v);

        N = n;
        def = v;

        for (int i = 0; i < n; i++)
            tree[n + i] = a[i];

        if (set_parent)
            for (int i = n - 1; i >= 1; i--)
                tree[i] = stFun(tree[2 * i], tree[2 * i + 1]);
    }
    // [ql, qr]
    T get_range(int ql, int qr) { return _get_range(1, 0, N - 1, ql, qr); }
    T _get_range(int node, int sl, int sr, int ql, int qr)
    {
        if (ql <= sl && sr <= qr)
            return tree[node];
        if (sr < ql || qr < sl)
            return def;

        return stFun(_get_range(2 * node, sl, (sl + sr) / 2, ql, qr),
                     _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr));
    }

    void update_node(int ind, T val)
    {
        tree[ind += N] = val;
        while (ind / 2 >= 1)
        {
            ind /= 2;
            tree[ind] = stFun(tree[2 * ind], tree[2 * ind + 1]);
        }
    }

    void check_tree()
    {
        for (int i = 0; i < tree_size; i++)
            cout << i << ": " << tree[i] << "\n";
    }

    T get_leaf(int x) { return tree[x + N]; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(n, Q);
    V<LL> rdv(a, n);
    VV<LL> b(n, V<LL>());

    return 0;
}
