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
#define rd(...) \
  __VA_ARGS__;  \
  read(__VA_ARGS__)
#define rdv(value, ...) \
  value(__VA_ARGS__);   \
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

void solve(LL cs)
{
  LL rd(n);
  V<LL> row(n), col(n), row_sum(n + 1, 0), col_sum(n + 1, 0), row_sq_sum(n + 1, 0), col_sq_sum(n + 1, 0);
  rep(i, n) cin >> row[i] >> col[i];

  vsorta(row);
  vsorta(col);
  rep(i, n)
  {
    row_sum[i + 1] = (row_sum[i] + row[i]) % MOD1;
    col_sum[i + 1] = (col_sum[i] + col[i]) % MOD1;
    row_sq_sum[i + 1] = (row_sq_sum[i] + (row[i] * row[i]) % MOD1) % MOD1;
    col_sq_sum[i + 1] = (col_sq_sum[i] + (col[i] * col[i]) % MOD1) % MOD1;
  }

  LL ans = 0LL;
  LL rd(Q);
  while (Q--)
  {
    LL rd(x, y);
    auto itrow = lower_bound(row.begin(), row.end(), x);
    auto itcol = lower_bound(col.begin(), col.end(), y);
    auto X = distance(row.begin(), itrow);
    auto Y = distance(col.begin(), itcol);

    LL xx = ((x * x) % MOD1 * X) % MOD1;
    LL aax = row_sq_sum[X];
    LL axq2 = ((x * row_sum[X]) * 2 % MOD1 + MOD1) % MOD1;
    ans = ((ans + aax + xx - axq2) % MOD1 + MOD1) % MOD1;

    LL yy = ((y * y) % MOD1 * Y) % MOD1;
    LL aay = col_sq_sum[Y];
    LL ayq2 = ((y * col_sum[Y]) * 2 % MOD1 + MOD1) % MOD1;
    ans = ((ans + aay + yy - ayq2) % MOD1 + MOD1) % MOD1;

    LL xx2 = ((x * x) % MOD1 * (n - X)) % MOD1;
    LL aax2 = (row_sq_sum[n] - row_sq_sum[X] + MOD1) % MOD1;
    LL axq22 = ((x * (row_sum[n] - row_sum[X])) * 2 % MOD1 + MOD1) % MOD1;
    ans = ((ans + xx2 + aax2 - axq22) % MOD1 + MOD1) % MOD1;

    LL yy2 = ((y * y) % MOD1 * (n - Y)) % MOD1;
    LL aay2 = (col_sq_sum[n] - col_sq_sum[Y] + MOD1) % MOD1;
    LL ayq22 = ((y * (col_sum[n] - col_sum[Y])) * 2 % MOD1 + MOD1) % MOD1;
    ans = ((ans + yy2 + aay2 - ayq22) % MOD1 + MOD1) % MOD1;
  }
  printf("Case #%lld: %lld\n", cs, ans);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(T);
  rep(i, T)
  {
    solve(i + 1);
  }
  Ret;
}
