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

#define MAX_N 1000000
int main()
{
  FAST;
  stack<char> st;
  ll f = 0, b = 0, n;
  string s;
  cin >> n >> s;
  repa(i, 0, n)
  {
    if (!st.empty() && st.top() == '(' && s[i] == ')')
      st.pop();
    else
      st.push(s[i]);
  }
  while (!st.empty())
  {
    if (st.top() == ')')
      f++;
    if (st.top() == '(')
      b++;
    st.pop();
  }
  repa(i, 0, f)
  {
    cout << '(';
  }
  cout << s;
  repa(i, 0, b)
  {
    cout << ')';
  }
  cout << endl;
  return 0;
}