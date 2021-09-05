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
#define iv vector<ll>
#define dv vector<double>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, e) for (ll i = 0; i < e; i++)
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define pr(x) cout << x
#define prd(x) cout << setprecision(50) << x
#define pn() cout << '\n'
#define ps() cout << ' '
#define ret return
#define MOD2 998244353
#define MAX_N 101000
ll zero = 0;

ll rl()
{
  ll n;
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
      prime_numbers.PB(i);
  }
}

int main()
{
  FAST;
  prepare_prime_numbers();
  vector<ll>::iterator it;
  ll n = rl();
  it = lower_bound(prime_numbers.begin(), prime_numbers.end(), n);
  pr(*it);
  pn();
  ret 0;
}