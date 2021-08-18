#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define repin(a, n)          \
  for (ll i = 0; i < n; i++) \
  cin >> a[i]
#define sort_vec(v) sort(v.begin(), v.end())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  string s;
  ll n;
  deque<char> dq;
  map<string, bool> mp;
  cin >> s;
  cin >> n;
  if (n > s.size())
  {
    cout << 0 << endl;
    return 0;
  }
  repa(i, 0, n)
  {
    dq.push_back(s[i]);
  }

  string t(dq.begin(), dq.end());
  mp[t] = true;
  repa(i, n, s.size())
  {
    dq.pop_front();
    dq.push_back(s[i]);
    string t(dq.begin(), dq.end());
    mp[t] = true;
  }
  cout << mp.size() << endl;
  return 0;
}