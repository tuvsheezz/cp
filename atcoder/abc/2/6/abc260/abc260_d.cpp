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

struct UnionFind
{
    vector<long long> parent, size;
    long long size_max = 0, count;

    void init(long long n)
    {
        parent.resize(n, -1);
        size.resize(n, 1);
        count = n;
        size_max = 1;
    }
    long long root(long long x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
    bool same(long long x, long long y) { return root(x) == root(y); }
    void unite(long long x, long long y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        parent[y] = x;
        size[x] += size[y];
    }
    long long count_of_sets() { return count; }
    long long get_union_size(long long x) { return size[root(x)]; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(n, k);
    V<LL> rdv(a, n);
    set<LL> st;
    UnionFind uf;
    uf.init(n);
    rep(i, n)
    {
        a[i]--;
        auto it = st.lower_bound(a[i]);
        if (it != st.end())
        {
            uf.unite(a[i], *it);
            st.erase(*it);
        }
        if (uf.get_union_size(a[i]) < k)
            st.insert(a[i]);
        // prn(uf.parent);
        // repauto(x, st)
        // {
        //     cout << x << " ";
        // }
        // PN;
    }
    V<LL> b(n), ans(n, -1);
    rep(i, n) { b[a[i]] = i; }
    rep(i, n)
    {
        if (uf.get_union_size(a[i]) == k)
            ans[a[i]] = b[uf.root(a[i])] + 1;
    }
    rep(i, n) { prn(ans[i]); }
    Ret;
}
