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

struct SegTree
{
    LL left, right;
    LL maxi = INT32_MIN;
    SegTree *left_child = nullptr, *right_child = nullptr;

    SegTree(LL lb, LL rb)
    {
        left = lb;
        right = rb;
    }

    void extend()
    {
        if (!left_child && left + 1 < right)
        {
            LL t = (left + right) / 2;
            left_child = new SegTree(left, t);
            right_child = new SegTree(t, right);
        }
    }

    void set(LL k, LL x)
    {
        extend();
        maxi = max(x, maxi);
        if (left_child)
        {
            if (k < left_child->right)
                left_child->set(k, x);
            else
                right_child->set(k, x);
        }
    }

    LL get_max(LL lq, LL rq)
    {
        if (lq <= left && right <= rq)
            return maxi;
        if (max(left, lq) >= min(right, rq))
            return INT32_MIN;
        extend();
        return max(left_child->get_max(lq, rq), right_child->get_max(lq, rq));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL rd(n);
    VV<LL> a(n, V<LL>(3));
    rep(i, n)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        vsorta(a[i]);
    }
    vsorta(a);
    VV<PLL> b;
    V<LL> added(n, false);
    rep(i, n)
    {
        if (added[i])
            continue;

        LL j = i;
        V<PLL> v;
        while (j < n && a[j][0] == a[i][0])
        {
            v.PB({a[j][1], a[j][2]});
            added[j] = true;
            j++;
        }
        b.PB(v);
    }

    SegTree st(0, 1e10);

    repd(i, b.size() - 1, 0)
    {
        repauto(x, b[i])
        {
            auto mx = st.get_max(x.F + 1, 1e10);
            if (mx > x.S)
            {
                Yes;
                return 0;
            }
        }
        repauto(x, b[i]) st.set(x.F, x.S);
    }
    No;
    return 0;
}
