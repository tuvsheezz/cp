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
template <class T, class D>
struct SegmentTree
{
  V<D> tree;
  T tree_size, N;
  D def;
  D(*ope)
  (D, D);

  void init(T n, V<D> a, D (*op)(D, D), bool set_parent = true, D v = 0)
  {
    while (__builtin_popcount(n) != 1)
    {
      a.PB(v);
      n++;
    }
    tree.resize(2 * n, v);
    tree_size = 2 * n;
    N = n;
    def = v;
    ope = op;
    rep(i, n) { tree[n + i] = a[i]; }
    if (set_parent)
      repd(i, n - 1, 1) { tree[i] = ope(tree[2 * i], tree[2 * i + 1]); }
  }

  D get_range(T ql, T qr) { ret _get_range(1, 0, N - 1, ql, qr); }
  D _get_range(T node, T sl, T sr, T ql, T qr)
  {
    if (ql <= sl && sr <= qr)
      ret tree[node];
    if (sr < ql || qr < sl)
      ret def;
    ret ope(_get_range(2 * node, sl, (sl + sr) / 2, ql, qr), _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr));
  }

  void update_node(T ind, D val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      tree[ind] = ope(tree[2 * ind], tree[2 * ind + 1]);
    }
  }
  D get_leaf(LL x) { ret tree[x + N]; }
};

V<LL> fope(V<LL> a, V<LL> b)
{
  V<LL> r(26, 0);
  rep(i, 26) { r[i] = a[i] + b[i]; }
  ret r;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL n = rd<LL>();
  STR s = rd<STR>();
  V<V<LL>> a(n, V<LL>(26, 0));
  rep(i, n) { a[i][s[i] - 'a']++; }
  SegmentTree<LL, V<LL>> st;
  st.init(n, a, &fope, true, V<LL>(26, 0));

  LL q = rd<LL>();
  while (q--)
  {
    LL com = rd<LL>();
    if (com == 2)
    {
      LL l = rd<LL>(), r = rd<LL>(), ans = 0;
      V<LL> k = st.get_range(l - 1, r - 1);
      rep(i, 26)
      {
        if (k[i] > 0)
          ans++;
      }
      pr(ans);
      PN;
    }
    else
    {
      LL ind = rd<LL>();
      char ch = rd<char>();
      V<LL> v = V<LL>(26, 0);
      v[ch - 'a']++;
      st.update_node(ind - 1, v);
    }
  }
  Ret;
}
