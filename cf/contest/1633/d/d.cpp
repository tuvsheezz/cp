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
#define prd(x) cout << fixed << setprecision(50) << x
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
#define MAX_N 1111

V<LL> p(MAX_N, INF);

LL knapSack(LL W, V<LL> &wt, V<LL> &val, LL n)
{
  // making and initializing dp array
  LL dp[W + 1];
  memset(dp, 0, sizeof(dp));

  for (LL i = 1; i < n + 1; i++)
  {
    for (LL w = W; w >= 0; w--)
    {

      if (wt[i - 1] <= w)
        // finding the maximum value
        dp[w] = max(dp[w],
                    dp[w - wt[i - 1]] + val[i - 1]);
    }
  }
  return dp[W]; // returning the maximum value of knapsack
}

void solve()
{
  LL rd(n, k);
  V<LL> rdv(b, n);
  V<LL> rdv(c, n);

  // VV<LL> dp(n + 1, V<LL>(k + 1, 0));

  V<LL> q(n), q2(n);
  LL sum = 0, mn = INF;
  rep(i, n)
  {
    q[i] = p[b[i]], q2[i] = c[i];
    sum += q[i];
    mn = min(mn, q[i]);
  }

  if (mn > k)
  {
    pr(0);
  }
  else if (k >= sum)
  {
    LL ans = 0;
    rep(i, n) { ans += q2[i]; }
    pr(ans);
  }
  else
    pr(knapSack(k, q, q2, n));

  // V<PLL> q(n);
  // rep(i, n) { q[i] = MP(p[b[i]], c[i]); }

  // repa(i, 1, n + 1)
  // {
  //   LL wi = q[i - 1].F, vi = q[i - 1].S;
  //   rep(j, k + 1)
  //   {
  //     if (vi == INF)
  //       vi = 0;
  //     rep(j, k + 1)
  //     {
  //       if (j - wi >= 0)
  //         dp[i][j] = max(dp[i - 1][j], vi + dp[i - 1][j - wi]);
  //       else
  //         dp[i][j] = dp[i - 1][j];
  //     }
  //   }
  // }

  // pr(dp[n][k]);
  PN;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  p[1] = 0;

  repa(i, 1, MAX_N)
  {
    for (int j = 1; j <= i; j++)
    {
      if (i + i / j >= MAX_N)
        continue;
      p[i + i / j] = min(p[i + i / j], p[i] + 1);
    }
  }
  LL rd(T);

  while (T--)
  {
    solve();
  }
  Ret;
}
