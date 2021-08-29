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
#define MAX_N 100100

int main()
{
  FAST;
  ll n;
  cin >> n;
  stack<char> st;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      st.push('A');
      n--;
    }
    if (n > 0)
      st.push('B');
    n /= 2;
  }

  while (!st.empty())
  {
    cout << st.top();
    st.pop();
  }
  cout << '\n';
  return 0;
}