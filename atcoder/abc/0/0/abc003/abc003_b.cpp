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
  string s1;
  string s2;
  char arr[] = {'a', 't', 'c', 'o', 'd', 'e', 'r', '@'};
  cin >> s1;
  cin >> s2;
  repa(i, 0, s1.size())
  {
    char *at1 = find(begin(arr), end(arr), s1[i]);
    char *at2 = find(begin(arr), end(arr), s2[i]);
    if (s1[i] != s2[i] && s1[i] != '@' && s2[i] != '@')
    {
      cout << "You will lose" << endl;
      return 0;
    }
    else if (s1[i] == '@' && at2 == end(arr))
    {
      cout << "You will lose" << endl;
      return 0;
    }
    else if (s2[i] == '@' && at1 == end(arr))
    {
      cout << "You will lose" << endl;
      return 0;
    }
  }
  cout << "You can win" << endl;
  return 0;
}