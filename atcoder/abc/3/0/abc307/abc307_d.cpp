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

bool xxx(bool a, bool b)
{
    return a || b;
}

template <class T>
struct SegmentTree
{
    vector<T> tree;
    int tree_size, N;
    T def;

    SegmentTree(int n, T v)
    {
        while (__builtin_popcount(n) != 1)
        {
            n++;
        }
        tree_size = 2 * n;
        tree.resize(tree_size, v);

        N = n;
        def = v;
    }
    // [ql, qr]
    void update_range(int ql, int qr, T v) { _update_range(1, 0, N - 1, ql, qr, v); }
    void _update_range(int node, int sl, int sr, int ql, int qr, T v)
    {
        if (ql <= sl && sr <= qr)
        {
            tree[node] = v;
            return;
        }
        if (sr < ql || qr < sl)
            return;
        _update_range(2 * node, sl, (sl + sr) / 2, ql, qr, v);
        _update_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr, v);
    }

    T get_point(int ind)
    {
        T x = tree[ind += N];
        while (ind / 2 >= 1)
        {
            ind /= 2;
            x = xxx(tree[ind], x);
        }
        return x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL rd(n);
    STR rd(s);

    stack<PLL> st;
    SegmentTree<bool> seg(n, false);
    rep(i, n)
    {
        if (s[i] == '(')
            st.push({1, i});
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top().F == 1)
            {
                LL lef = st.top().S;
                st.pop();
                seg.update_range(lef, i, true);
            }
            else
                st.push({2, i});
        }
    }

    rep(i, n)
    {
        if (!seg.get_point(i))
            pr(s[i]);
    }
    PN;

    return 0;
}
