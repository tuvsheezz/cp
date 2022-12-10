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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL rd(n, m, k);
    V<LL> rdv(a, n);
    PQD<PLL> now;
    PQA<PLL> waiting;
    V<LL> ans;
    V<bool> in_pq(n, false), oor(n, false);

    rep(i, m) waiting.push(MP(a[i], i));
    LL cur_sum = 0, cc = 0;
    rep(i, k)
    {
        now.push(waiting.top());
        cur_sum += waiting.top().F;
        in_pq[waiting.top().S] = true;
        waiting.pop();
        cc++;
    }
    prn(a);
    prn(now.size());
    prn(in_pq);
    ans.PB(cur_sum);
    repa(i, 1, n - m + 1)
    {
        while (!waiting.empty() && waiting.top().S < i)
            waiting.pop();

        while (!now.empty() && now.top().S < i)
        {
            in_pq[now.top().S] = false;
            now.pop();
        }

        waiting.push(MP(a[i + m - 1], i));
        prn(a[i + m - 1]);
        if (in_pq[i - 1] == true)
        {
            cur_sum -= a[i - 1];
            in_pq[i - 1] = false;
            cc--;
            now.push(waiting.top());
            cur_sum += waiting.top().F;
            in_pq[waiting.top().S] = true;
            waiting.pop();
        }
        while (cc < k)
        {
            now.push(waiting.top());
            cur_sum += waiting.top().F;
            in_pq[waiting.top().S] = true;
            waiting.pop();
            cc++;
        }
        if (waiting.top().F < now.top().F)
        {
            in_pq[now.top().S] = false;
            in_pq[waiting.top().S] = true;

            cur_sum += waiting.top().F;
            cur_sum -= now.top().F;

            waiting.push(now.top());
            now.pop();

            now.push(waiting.top());
            waiting.pop();
        }
        ans.push_back(cur_sum);
        prn(in_pq);
    }
    prn(ans);
    Ret;
}
