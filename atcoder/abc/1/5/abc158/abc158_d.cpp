#include <bits/stdc++.h>
using namespace std;
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
#define MAX_N 100100

ll q, t, f;
bool R = 0;
char c;
string s;
deque<char> dq;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> q;
  repa(i, 0, s.length()) dq.push_back(s[i]);
  repa(i, 0, q)
  {
    cin >> t;
    if (t & 1)
    {
      R = !R;
      continue;
    }
    cin >> f >> c;
    if (R)
      f++;
    (f & 1) ? dq.push_front(c) : dq.push_back(c);
  }
  if (R)
  {
    for (auto itr = dq.rbegin(); itr != dq.rend(); ++itr)
      cout << *itr;
    return 0;
  }

  for (auto itr = dq.begin(); itr != dq.end(); ++itr)
    cout << *itr;
  return 0;
}
