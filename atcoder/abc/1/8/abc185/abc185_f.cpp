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

template <class T>
T fsum(T a, T b) { ret a + b; }
template <class T>
T fmin(T a, T b) { ret min(a, b); }
template <class T>
T fmax(T a, T b) { ret max(a, b); }
template <class T>
T fxor(T a, T b) { ret a ^ b; }
template <class T>
struct SegmentTree
{
  V<T> tree;
  T tree_size, N, def;
  T(*ope)
  (T, T);

  void init(T n, V<T> a, T (*op)(T, T), bool set_parent = true, T v = 0)
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

  T get_range(T ql, T qr) { ret _get_range(1, 0, N - 1, ql, qr); }
  T _get_range(T node, T sl, T sr, T ql, T qr)
  {
    if (ql <= sl && sr <= qr)
      ret tree[node];
    if (sr < ql || qr < sl)
      ret def;
    ret ope(_get_range(2 * node, sl, (sl + sr) / 2, ql, qr), _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr));
  }

  T get_node(T ind)
  {
    LL sum = tree[ind += N];
    while (ind / 2 >= 1)
    {
      sum += tree[ind /= 2];
    }
    ret sum;
  }

  void update_range(T ql, T qr, T v) { _update_range(1, 0, N - 1, ql, qr, v); }
  void _update_range(T node, T sl, T sr, T ql, T qr, T v)
  {
    if (ql <= sl && sr <= qr)
    {
      tree[node] += v;
      ret;
    }
    if (sr < ql || qr < sl)
      ret;
    _update_range(2 * node, sl, (sl + sr) / 2, ql, qr, v);
    _update_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr, v);
  }

  void update_node(T ind, T val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      tree[ind] = ope(tree[2 * ind], tree[2 * ind + 1]);
    }
  }
  void check_tree() { rep(i, tree_size) cout << i << ": " << tree[i] << "\n"; }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL n = rd<LL>(), q = rd<LL>();
  V<LL> a = rv<LL>(n);
  SegmentTree<LL> st;
  st.init(n, a, &fxor, true, 0LL);
  while (q--)
  {
    LL t = rd<LL>(), x = rd<LL>(), y = rd<LL>();
    if (t == 1)
      st.update_node(x - 1, st.get_range(x - 1, x - 1) ^ y);
    else
    {
      pr(st.get_range(x - 1, y - 1));
      PN;
    }
  }
  Ret;
}
