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
  string S;
  cin >> S;
  for (int i = 0; i < 8; i++)
  {
    int C = (S[0] - '0');
    for (int j = 0; j < 3; j++)
    {
      if ((i / (1 << j)) % 2 == 0)
        C -= (S[j + 1] - '0');
      else
        C += (S[j + 1] - '0');
    }
    if (C == 7)
    {
      for (int j = 0; j < 3; j++)
      {
        cout << S[j];
        if ((i / (1 << j)) % 2 == 0)
          cout << "-";
        else
          cout << "+";
      }
      cout << S[3];
      cout << "=7" << endl;
      break;
    }
  }
}