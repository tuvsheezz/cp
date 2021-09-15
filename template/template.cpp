#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define M_PI 3.141592653589793238462643383279502884L
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define iv vector<ll>
#define ivv vector<vector<ll>>
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
struct UnionFind
{
  ll par[MAX_N];
  ll ran[MAX_N] = {0};
  ll siz[MAX_N];
  ll size_max = 0;
  ll count;

  void init(ll n)
  {
    repa(i, 0, n)
    {
      par[i] = i;
      siz[i] = 1;
    }
    count = n;
    size_max = 1;
  }

  ll root(ll x) { ret par[x] == x ? x : par[x] = root(par[x]); }
  bool same(ll x, ll y) { ret root(x) == root(y); }
  void unite(ll x, ll y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      ret;

    if (siz[x] < siz[y])
      swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    size_max = max(siz[x], size_max);
    count--;
  }
  ll numbers_of_sets() { ret count; }
};

ll big_pow(ll x, ll n, ll mod)
{
  if (n == 0)
    ret 1;
  ll z = big_pow(x * x % mod, n / 2, mod);
  if (n & 1)
    z = z * x % mod;
  ret z;
}

vector<bool> is_prime(MAX_N, true);
iv prime_numbers;

void prepare_prime_numbers()
{
  is_prime[0] = false;
  is_prime[1] = false;
  repa(i, 2, MAX_N + 1)
  {
    if (!is_prime[i])
      continue;
    ll mult = 2;
    while (i * mult <= MAX_N)
    {
      is_prime[i * mult] = false;
      mult++;
    }
  }
  repa(i, 0, MAX_N + 1)
  {
    if (is_prime[i])
      prime_numbers.push_back(i);
  }
}

bool is_prime_simple(ll n)
{
  if (n == 1)
    ret false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      ret false;
  }
  ret true;
}

iv prime_divisors(ll n)
{
  iv res;
  ll tmp = n;
  for (auto const &x : prime_numbers)
  {
    if (x * x > n)
      break;
    while (n % x == 0)
    {
      res.push_back(x);
      n /= x;
    }
  }
  if (n > 1)
    res.push_back(n);
  sort(res.begin(), res.end());
  ret res;
}

ll fact(ll n, ll mod)
{
  ll r = 1;
  if (n < 2)
    ret r;
  repa(i, 1, n + 1)
  {
    r = (r * i) % mod;
  }
  ret r;
}

// BIT全検索
// repa(i, 0, 1 << (n - 1)) {
// 000001 -> 111111
//   repa(j, 0, n + 1) {
//     if(i >> j & 1) {
//         1? 0?
//     }
//   }
// }

void solve()
{
}

int main()
{
  FAST;
  ll T = rl();
  while (T--)
  {
    solve();
  }
  Ret;
}
