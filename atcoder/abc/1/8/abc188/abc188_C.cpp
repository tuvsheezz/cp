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
  ll n, a[MAX_N], N;
  bin_log[1] = 0;
  repa(i, 2, MAX_N) bin_log[i] = bin_log[i / 2] + 1;

  cin >> n;
  N = (1 << n);
  repa(i, 0, N)
  {
    cin >> a[i];
    st[i][0] = a[i];
  }

  repa(j, 1, LOG)
  {
    for (int i = 0; i + (1 << j) - 1 < N; i++)
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }

  ll q = min(spt_query(0, N / 2 - 1), spt_query(N / 2, N - 1));
  repa(i, 0, N)
  {
    if (a[i] == q)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
}