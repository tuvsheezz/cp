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

LL solve()
{
  LL row = rd<LL>(), col = rd<LL>(), tar = rd<LL>(), cur = 0, ans;
  V<LL> ab(col, 0), be(col, 0);
  V<bool> cu(col, 0);
  V<V<bool>> G(row, V<bool>(col, false));
  rep(i, row)
  {
    rep(j, col)
    {
      char c = rd<char>();
      if (c == 'X')
      {
        G[i][j] = true;
      }
    }
  }
  rep(i, tar - 1)
  {
    rep(j, col)
    {
      if (G[i][j])
        ab[j]++;
    }
  }
  repa(i, tar, row)
  {
    rep(j, col)
    {
      if (G[i][j])
        be[j]++;
    }
  }
  rep(i, col)
  {
    if (G[tar - 1][i])
    {
      cur++;
      cu[i] = true;
    }
    else
    {
      cu[i] = false;
    }
  }
  ans = cur;

  // upward + levitate
  LL up = 0;
  repa(i, tar, row)
  {
    up++;
    rep(j, col)
    {
      if (!cu[j] && !G[i][j])
      {
        continue;
      }
      else if (!cu[j] && G[i][j])
      {
        cu[j] = true;
        cur++;
      }
      else if (cu[j])
      {
        if (tar - 1 > ab[j])
        {
          ab[j]++;
          if (!G[i][j])
          {
            cur--;
            cu[j] = false;
          }
        }
      }
    }
    ans = min(cur + up, ans);
  }
  // last upward
  up++;
  rep(i, col)
  {
    if (!cu[i])
      continue;

    if (tar - 1 > ab[i])
    {
      cur--;
      cu[i] = false;
    }
  }
  ans = min(cur + up, ans);

  // downward + levitate
  cur = 0;
  LL down = 0;
  rep(i, col)
  {
    if (G[tar - 1][i])
    {
      cur++;
      cu[i] = true;
    }
    else
    {
      cu[i] = false;
    }
  }
  repd(i, tar - 2, 0)
  {
    down++;
    rep(j, col)
    {
      if (!cu[j] && !G[i][j])
      {
        continue;
      }
      else if (!cu[j] && G[i][j])
      {
        cu[j] = true;
        cur++;
      }
      else if (cu[j])
      {
        if (row - tar > be[j])
        {
          be[j]++;
          if (!G[i][j])
          {
            cur--;
            cu[j] = false;
          }
        }
      }
    }
    ans = min(cur + down, ans);
  }

  // last downward
  down++;
  rep(i, col)
  {
    if (!cu[i])
      continue;

    if (row - tar > be[i])
    {
      cur--;
      cu[i] = false;
    }
  }
  ans = min(cur + down, ans);

  ret ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL T = rd<LL>();
  rep(i, T) { cout << "Case #" << i + 1 << ": " << solve() << '\n'; }
  Ret;
}
