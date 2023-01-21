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
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;
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
#define rd(...) \
  __VA_ARGS__;  \
  read(__VA_ARGS__)
#define rdv(value, ...) \
  value(__VA_ARGS__);   \
  cin >> value
template <class T>
auto &operator>>(istream &is, vector<T> &xs)
{
  for (auto &x : xs)
    is >> x;
  return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> &xs)
{
  int sz = xs.size();
  rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
  return os;
}
template <class T, class Y>
auto &operator<<(ostream &os, pair<T, Y> &xs)
{
  os << "{" << xs.first << ", " << xs.second << "}";
  return os;
}
template <class T, class Y>
auto &operator>>(istream &is, vector<pair<T, Y>> &xs)
{
  for (auto &[x1, x2] : xs)
    is >> x1 >> x2;
  return is;
}
template <class... Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prs(x) cout << x << ' '
#define prn(x) cout << x << '\n'
#define prd() cout << fixed << setprecision(50);
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct BoolTree
{
  vector<bool> tree;
  LL tree_size, N;
  bool def;

  BoolTree(LL n)
  {
    while (__builtin_popcount(n) != 1)
    {
      n++;
    }
    tree.resize(2 * n, false);
    tree_size = 2 * n;
    N = n;
    def = true;
  }

  bool get_range(LL ql, LL qr) { return _get_range(1, 0, N - 1, ql, qr); }
  bool _get_range(LL node, LL sl, LL sr, LL ql, LL qr)
  {
    if (ql <= sl && sr <= qr)
      return tree[node];
    if (sr < ql || qr < sl)
      return def;
    return _get_range(2 * node, sl, (sl + sr) / 2, ql, qr) && _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr);
  }

  void update_node(LL ind, bool val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      tree[ind] = tree[2 * ind] && tree[2 * ind + 1];
    }
  }
  
  bool get_leaf(LL x) { return tree[x + N]; }
};

struct SegmentTree
{
  vector<vector<LL>> tree;
  LL tree_size, N;
  V<LL> def;

  SegmentTree(LL n)
  {
    while (__builtin_popcount(n) != 1)
    {
      n++;
    }
    def.resize(26, 0);
    tree.resize(2 * n, def);
    tree_size = 2 * n;
    N = n;
  }

  V<LL> get_range(LL ql, LL qr) { return _get_range(1, 0, N - 1, ql, qr); }
  V<LL> _get_range(LL node, LL sl, LL sr, LL ql, LL qr)
  {
    if (ql <= sl && sr <= qr)
      return tree[node];
    if (sr < ql || qr < sl)
      return def;
    auto xx = _get_range(2 * node, sl, (sl + sr) / 2, ql, qr);
    auto yy = _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr);
    rep(i, 26) xx[i] += yy[i];
    return xx;
  }

  void update_node(LL ind, V<LL> val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      auto xx = tree[2 * ind];
      auto yy = tree[2 * ind + 1];
      rep(i, 26) xx[i] += yy[i];
      tree[ind] = xx;
    }
  }
  V<LL> get_leaf(LL x) { return tree[x + N]; }
};


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n);
  STR rd(s);
  LL rd(Q);
  SegmentTree st(n);
  BoolTree bt(n);
  
  rep(i, n) {
    V<LL> x(26, 0);
    x[s[i] - 'a']++;
    st.update_node(i, x);

    bool ll, rr;
    if(i == 0) ll = true;
    else {
      ll = s[i] >= s[i - 1];
    }
    if(n - 1 == i) rr = true;
    else {
      rr = s[i] <= s[i + 1];
    }
    bt.update_node(i, rr && ll);
  }

  while(Q--) {
    LL rd(com);
    if(com == 1) {
      LL rd(ind);
      ind--;
      char rd(c);
      s[ind] = c;
      V<LL> x(26, 0);
      x[c - 'a']++;
      st.update_node(ind, x);
      
      bool ll, rr;
      
      if(ind == 0) ll = true;
      else {
        ll = s[ind] >= s[ind - 1];
      }

      if(n - 1 == ind) rr = true;
      else {
        rr = s[ind] <= s[ind + 1];
      }
      bt.update_node(ind, rr && ll);

      if(ind > 0) {
        LL ind2 = ind - 1;
        if(ind2 == 0) ll = true;
        else {
          ll = s[ind2] >= s[ind2 - 1];
        }
        if(n - 1 == ind2) rr = true;
        else {
          rr = s[ind2] <= s[ind2 + 1];
        }
        bt.update_node(ind2, rr && ll);
        ind2++;
      }
      if(ind < n - 1) {
        LL ind3 = ind + 1;
        if(ind3 == 0) ll = true;
        else {
          ll = s[ind3] >= s[ind3 - 1];
        }
        if(n - 1 == ind3) rr = true;
        else {
          rr = s[ind3] <= s[ind3 + 1];
        }
        bt.update_node(ind3, rr && ll);
      }
    } else {
      LL rd(l, r);
      l--, r--;
      auto all = st.get_range(0, n);
      auto range = st.get_range(l, r);
      LL L = 0, R = 25;
      while(range[L] == 0) L++;
      while(range[R] == 0) R--;
      bool f = true;
      repa(i, L + 1, R) {
        if(all[i] != range[i]) f = false;
      }
      bool ff = true;
      if(l < r) {
        bool tmpL = bt.get_leaf(l);
        bool tmpR = bt.get_leaf(r);

        bool ll, rr;
        if(n - 1 == l) rr = true;
        else {
          rr = s[l] <= s[l + 1];
        }

        bt.update_node(l, rr);

        if(r == 0) ll = true;
        else {
          ll = s[r] >= s[r - 1];
        }
        bt.update_node(r, ll);

        ff = bt.get_range(l, r);

        bt.update_node(l, tmpL);
        bt.update_node(r, tmpR);
      }


      (f && ff) ? Yes : No;
    }
  }
  return 0;
}
