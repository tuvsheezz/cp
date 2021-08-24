#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
#define MAX_N 100100
#define INF 10e17
ll memo[50][50][60];

ll cut(ll n, ll m, ll k) {
  if(k == 0 || n * m == k || memo[n][m][k])
    return memo[n][m][k];
  ll ans = INF;

  for(ll i = 1; i <= n - i; i++) {
    for(ll j = 0; j <= k; j++) {
      ll cost = m * m + cut(i, m, k - j) + cut(n - i, m, j);
      ans = min(ans, cost);
    }
  }
  for(ll i = 1; i <= m - i; i++) {
    for(ll j = 0; j <= k; j++) {
      ll cost = n * n + cut(n, i, k - j) + cut(n, m - i, j);
      ans = min(ans, cost);
    }
  }
  memo[n][m][k] = ans;
  return ans;
}

void solve() {
  ll N, M, K;
  cin >> N >> M >> K;
  cout << cut(N, M, K) << '\n';
}

int main() {
  FAST;
  ll t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}