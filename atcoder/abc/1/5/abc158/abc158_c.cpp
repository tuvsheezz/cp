#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
#define IV vector<LL>
#define DV vector<double>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define RP(i, e) for (LL i = 0; i < e; i++)
#define RPA(i, s, e) for (LL i = s; i < e; i++)
#define RPD(i, s, e) for (LL i = s; i >= e; i--)
#define VSA(v) sort(v.begin(), v.end())
#define VSD(v) sort(v.begin(), v.end(), greater<>())
#define SA(v, n) sort(v, v + n)
#define PR(x) cout << x
#define PRD(x) cout << setprecision(50) << x
#define PN() cout << '\n'
#define PS() cout << ' '
#define RET return
#define MOD2 998244353
#define MAX_N 100100
LL zero = 0;

LL RL()
{
  LL n;
  cin >> n;
  RET n;
}
STR RS()
{
  STR n;
  cin >> n;
  RET n;
}
IV RV(LL n)
{
  IV a(n, 0);
  RP(i, n) { cin >> a[i]; }
  RET a;
}

int main()
{
  FAST;
  LL a = RL(), b = RL();
  RP(i, 10000)
  {
    if (a == i * 8 / 100 && b == i / 10)
    {
      PR(i);
      PN();
      RET 0;
    }
  }
  PR("-1\n");
  RET 0;
}