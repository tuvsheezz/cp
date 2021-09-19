#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884L
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define iv vector<ll>
#define ivv vector<vector<ll>>
#define cv vector<char>
#define cvv vector<vector<char>>
#define dv vector<double>
#define MLL map<ll, ll>
#define MSL map<str, ll>
#define MLB map<ll, bool>
#define PQA priority_queue<ll, vector<ll>, greater<ll>>
#define PQD priority_queue<ll, vector<ll>, less<ll>>
#define IT iterator
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, e) for (ll i = 0; i < e; i++)
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define repauto(x, s) for (auto const &x : s)
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
#define MAX_N 100100
ll ssize(str s)
{
  ret(ll) s.size();
}
ll rl()
{
  ll n;
  cin >> n;
  ret n;
}
dd rd()
{
  dd n;
  cin >> n;
  ret n;
}
str rs()
{
  str n;
  cin >> n;
  ret n;
}
char rc()
{
  char n;
  cin >> n;
  ret n;
}
iv rv(ll n)
{
  iv a(n, 0);
  rep(i, n) { cin >> a[i]; }
  ret a;
}
dv rvd(ll n)
{
  dv a(n, 0);
  rep(i, n) { cin >> a[i]; }
  ret a;
}
ll vsum(iv v)
{
  ll s = 0;
  rep(i, (ll)v.size()) { s += v[i]; }
  ret s;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll h = rl(), w = rl();
  cvv a(h, cv(w));
  ivv dp(h, iv(w, 0));
  ivv dpp(h, iv(w, 0));
  rep(i, h) rep(j, w) a[i][j] = rc();
  rep(i, h)
  {
    rep(j, w)
    {
      if (a[i][j] == '#')
        continue;
      if (i > 0 && a[i - 1][j] == '.')
        dp[i][j] = dp[i - 1][j];
      else
      {
        ll k = i;
        while (k < h && a[k][j] == '.')
        {
          dp[i][j]++;
          k++;
        }
      }
      if (j > 0 && a[i][j - 1] == '.')
        dpp[i][j] = dpp[i][j - 1];
      else
      {
        ll k = j;
        while (k < w && a[i][k] == '.')
        {
          dpp[i][j]++;
          k++;
        }
      }
    }
  }
  ll ans = 0;

  rep(i, h) rep(j, w) ans = max(ans, dp[i][j] + dpp[i][j] - 1);

  pr(ans);
  PN;
  Ret;
}
