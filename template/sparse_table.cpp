#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353

const int MAX_N = 100100;
const int LOG = 17;
int st[MAX_N][LOG + 1];
int bin_log[MAX_N];

int spt_query(int L, int R)
{
  int k = bin_log[R - L + 1];
  return min(st[L][k], st[R - (1 << k) + 1][k]);
}

int main()
{
  FAST;
  ll n, mx = 0;

  bin_log[1] = 0;
  repa(i, 2, MAX_N) bin_log[i] = bin_log[i / 2] + 1;

  cin >> n;
  repa(i, 0, n) cin >> st[i][0];

  repa(j, 1, LOG)
  {
    for (int i = 0; i + (1 << j) - 1 < n; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }

  repa(i, 0, n)
  {
    repa(j, i, n)
    {
      ll R = j, L = i;
      mx = max(mx, (R - L + 1) * spt_query(L, R));
    }
  }

  cout << mx << '\n';
  return 0;
}