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

struct Sieve
{
    vector<long long> f, primes;
    Sieve(int n)
    {
        f.resize(n + 1, 0);
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; i++)
        {
            if (f[i] > 0)
                continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i * i; j <= n; j += i)
            {
                if (f[j] == 0)
                    f[j] = i;
            }
        }
    }
    bool is_prime(long long n) { return f[n] == n; }

    vector<long long> prime_factors(long long n)
    {
        vector<long long> r;
        while (n != 1)
        {
            r.push_back(f[n]);
            n /= f[n];
        }
        return r;
    }

    vector<pair<long long, long long>> prime_factors_count(long long n)
    {
        vector<long long> l = prime_factors(n);
        if (l.size() == 0)
            return {};
        vector<pair<long long, long long>> r(1, {l[0], 0});
        for (auto &x : l)
        {
            if (r.back().F == x)
                r.back().S++;
            else
                r.emplace_back(x, 1);
        }
        return r;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(N);

    Sieve s(100);

    auto x = s.primes;
    prn(x);

    LL ans = 0, n = x.size();
    rep(i, n)
    {
        if (x[i] * x[i] * x[i] * x[i] * x[i] > N)
            break;
        repa(j, i + 1, n)
        {
            if (x[i] * x[i] * x[j] * x[j] * x[j] > N)
                break;
            repa(k, j + 1, n)
            {
                if (x[i] * x[i] * x[j] * x[k] * x[k] > N)
                    break;
                ans++;
            }
        }
    }
    prn(ans);

    return 0;
}
