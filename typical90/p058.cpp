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
#define MAX_N 100000

struct Doubling
{
    vector<vector<long long>> table;
    long long n, ROW = 63;

    // 0 .. n - 1
    Doubling(vector<long long> a)
    {
        n = a.size();
        table.resize(ROW, vector<long long>(n, 0));
        for (long long i = 0; i < n; i++)
            table[0][i] = a[i];

        for (long long row = 1; row < ROW; row++)
            for (long long i = 0; i < n; i++)
                table[row][i] = table[row - 1][table[row - 1][i]];
    }

    long long query(long long x, long long step)
    {
        long long now = x;
        for (long long i = 0; i < ROW; i++)
            if ((step >> i) & 1)
                now = table[i][now];
        return now;
    }

    void debug()
    {
        for (long long i = 0; i < 6; i++)
        {
            for (long long j = 0; j < n; j++)
                cout << table[i][j] << " ";
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<long long> a(MAX_N + 1);
    rep(i, MAX_N + 1)
    {
        LL x = i;
        while (x > 0)
        {
            a[i] += x % 10;
            x /= 10;
        }
        a[i] = (a[i] + i) % MAX_N;
    }

    Doubling db(a);
    LL rd(x, k);
    prn(db.query(x, k));
    return 0;
}
