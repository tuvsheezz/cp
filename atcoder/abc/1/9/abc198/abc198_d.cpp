#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884L
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define MLL map<LL, LL>
#define MSL map<STR, LL>
#define MLB map<LL, bool>
#define PQA priority_queue<LL, V<LL>, greater<LL>>
#define PQD priority_queue<LL, V<LL>, less<LL>>
#define IT iterator
#define F first
#define S second
#define PB push_back
#define PLL pair<LL, LL>
#define MP make_pair
#define rep(i, e) for (LL i = 0; i < e; i++)
#define repa(i, s, e) for (LL i = s; i < e; i++)
#define repd(i, s, e) for (LL i = s; i >= e; i--)
#define repauto(x, s) for (auto x : s)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prd(x) cout << fixed << setprecision(50) << x
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100
LL ssize(STR s)
{
  ret(LL) s.size();
}
template <class T>
T rd()
{
  T n;
  cin >> n;
  ret n;
}
template <class T>
V<T> rv(T n)
{
  V<T> a(n, 0);
  rep(i, n) { cin >> a[i]; }
  ret a;
}
template <class T>
LL vsum(V<T> v)
{
  T s = 0;
  rep(i, (LL)v.size()) { s += v[i]; }
  ret s;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  STR s1 = rd<STR>(), s2 = rd<STR>(), s3 = rd<STR>();
  set<char> ch;
  rep(i, ssize(s1)) { ch.insert(s1[i]); }
  rep(i, ssize(s2)) { ch.insert(s2[i]); }
  rep(i, ssize(s3)) { ch.insert(s3[i]); }
  map<char, LL> mp;
  LL qqq = 0;
  repauto(x, ch) { mp[x] = qqq++; }
  if (ch.size() <= 10)
  {
    LL d[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do
    {
      if (d[mp[s1[0]]] == 0 || d[mp[s2[0]]] == 0 || d[mp[s3[0]]] == 0)
        continue;
      LL X = 0, Y = 0, Z = 0;
      rep(i, ssize(s1)) { X = X * 10 + d[mp[s1[i]]]; }
      rep(i, ssize(s2)) { Y = Y * 10 + d[mp[s2[i]]]; }
      rep(i, ssize(s3)) { Z = Z * 10 + d[mp[s3[i]]]; }

      if (X + Y == Z)
      {
        pr(X);
        PN;
        pr(Y);
        PN;
        pr(Z);
        PN;
        Ret;
      }

    } while (next_permutation(d, d + 10));
  }
  pr("UNSOLVABLE\n");
  Ret;
  Ret;
}
