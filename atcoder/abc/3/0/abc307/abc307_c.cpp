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

V<STR> FF(V<STR> a)
{
    LL h = a.size();
    LL w = a[0].size();
    LL top = INF, bottom = -1, left = INF, right = -1;
    rep(i, h) rep(j, w)
    {
        if (a[i][j] == '#')
        {
            top = min(top, i);
            bottom = max(bottom, i);
            left = min(left, j);
            right = max(right, j);
        }
    }
    V<STR> x(bottom - top + 1, STR(right - left + 1, '.'));
    repa(i, top, bottom + 1) repa(j, left, right + 1) x[i - top][j - left] = a[i][j];
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL rd(ha, wa);
    V<STR> rdv(a, ha);
    LL rd(hb, wb);
    V<STR> rdv(b, hb);
    LL rd(hc, wc);
    V<STR> rdv(c, hc);
    a = FF(a);
    ha = a.size();
    wa = a[0].size();
    b = FF(b);
    hb = b.size();
    wb = b[0].size();

    rep(i, hc) rep(j, wc) rep(k, hc) rep(l, wc)
    {
        VV<char> x(hc, V<char>(wc, '.'));
        if (i + ha <= hc && j + wa <= wc && k + hb <= hc && l + wb <= wc)
        {
            rep(ii, ha) rep(jj, wa) x[i + ii][j + jj] = a[ii][jj];
            rep(kk, hb) rep(ll, wb)
            {
                if (x[k + kk][l + ll] == '.')
                    x[k + kk][l + ll] = b[kk][ll];
            }
        }

        bool f = true;
        rep(iii, hc) rep(jjj, wc)
        {
            if (x[iii][jjj] != c[iii][jjj])
                f = false;
        }
        if (f)
        {
            Yes;
            return 0;
        }
    }
    No;
    return 0;
}
