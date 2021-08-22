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

str cyesno(bool cond) { return cond ? "Yes\n" : "No\n"; }
str uyesno(bool cond)
{ return (cond) ? "YES\n" : "NO\n"; }

struct UnionFind {
  ll par[MAX_N], ran[MAX_N] = {0}, siz[MAX_N], size_max = 0, count;

  void init(ll n) {
    repa(i, 0, n) { par[i] = i; siz[i] = 1; }
    count = n;
    size_max = 1;
  }

  ll root(ll x) { return par[x] == x ? x : par[x] = root(par[x]); }
  bool same(ll x, ll y) { return root(x) == root(y); }
  void unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (siz[x] < siz[y]) swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    size_max = max(siz[x], size_max);
    count--;
  }
  ll numbers_of_sets() { return count; }
};

ll big_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll z = big_pow(x * x % mod, n / 2, mod);
  if (n & 1) z = z * x % mod;
  return z;
}

vector<bool> is_prime(MAX_N, true);
vector<ll> prime_numbers;

void prepare_prime_numbers() {
  is_prime[0] = false; is_prime[1] = false;
  repa(i, 2, MAX_N + 1) {
    if (!is_prime[i]) continue;
    ll mult = 2;
    while (i * mult <= MAX_N) { is_prime[i * mult] = false; mult++; }
  }
  repa(i, 0, MAX_N + 1) { if (is_prime[i]) prime_numbers.push_back(i); }
}

bool is_prime_simple(ll n) {
  if (n == 1) return false;
  for (ll i = 2; i * i <= n; i++) { if (n % i == 0) return false; }
  return true;
}

vector<ll> prime_divisors(ll n)
{
  vector<ll> res;
  ll tmp = n;
  for (auto const &x : prime_numbers) { 
    if (x * x > n) break;
    while (n % x == 0) {
      res.push_back(x);
      n /= x;
    }
  }
  if (n > 1) res.push_back(n);
  sort(res.begin(), res.end());
  return res;
}

int main()
{
  FAST;
  ll n, c, ans = 0;
  cin >> n;
  dd l, r;
  vector<dd> left, right;
  repa(i, 0, n) {
    cin >> c >> l >> r;
    if(c == 2 || c == 4) r -= 0.5;
    if(c == 3 || c == 4) l += 0.5;
    left.push_back(l);
    right.push_back(r);
  }

  repa(i, 0, n) {
    repa(j, i + 1, n) {
      if (max(left[i], left[j]) <= min(right[i], right[j])) ans ++;
    }
  }
  cout << ans << '\n';
  return 0;
}