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


int main()
{
  FAST;
  ll n, i = 1;
  cin >> n;
  while(1) {
    ll multi = 1, tmp = i;
    while(tmp) {
      multi *= 10;
      tmp /= 10;
    }
    if(i * multi + i > n) {
      cout << i - 1 << '\n';
      return 0;
    }
    i++;
  }
}