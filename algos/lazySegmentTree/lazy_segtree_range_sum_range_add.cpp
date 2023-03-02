#include <bits/stdc++.h>
using namespace std;

template <class T>
struct LazySegmentTree
{
  vector<T> tree, lazy;
  vector<bool> vis;
  int tree_size, N;
  T def;

  T __initFun(T a, T b) { return a + b; }
  T __getFun(T a, T b) { return a + b; }

  T __evalUpdateParent(bool vis, T a, T b) { return a + b; }
  T __evalUpdateTree(T a, T b) { return a + b; }
  T __evalUpdateLazyChild(T a, T b) { return a + b / 2; }
  T __updateUpdatelazy(T a, T b, int sl, int sr) { return a + (sr - sl + 1) * b; }

  LazySegmentTree(int n, vector<T> a, bool set_parent = true, T v = 0)
  {
    while (__builtin_popcount(n) != 1)
    {
      a.push_back(v);
      n++;
    }
    tree_size = 2 * n;

    tree.resize(tree_size, v);
    lazy.resize(tree_size, v);
    vis.resize(tree_size, false);

    N = n;
    def = v;

    for (int i = 0; i < n; i++)
      tree[n + i] = a[i];

    if (set_parent)
      for (int i = n - 1; i >= 1; i--)
        tree[i] = __initFun(tree[2 * i], tree[2 * i + 1]);
  }

  void eval(int node, int sl, int sr)
  {
    if (vis[node])
    {
      tree[node] = __evalUpdateTree(tree[node], lazy[node]);
      if (sr > sl)
      {
        lazy[2 * node] = __evalUpdateLazyChild(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = __evalUpdateLazyChild(lazy[2 * node + 1], lazy[node]);
        vis[2 * node] = true;
        vis[2 * node + 1] = true;
      }
      lazy[node] = def;
      vis[node] = false;
    }
    while (node / 2 >= 1)
    {
      node /= 2;
      tree[node] = __initFun(
          __evalUpdateParent(vis[2 * node], lazy[2 * node], tree[2 * node]),
          __evalUpdateParent(vis[2 * node + 1], lazy[2 * node + 1], tree[2 * node + 1]));
    }
  }

  void update(int ql, int qr, T x) { return _update(1, 0, N - 1, ql, qr, x); }
  void _update(int node, int sl, int sr, int ql, int qr, T x)
  {
    if (node < 0 || tree_size <= node)
      return;

    eval(node, sl, sr);

    if (sr < ql || qr < sl)
      return;

    if (ql <= sl && sr <= qr)
    {
      lazy[node] = __updateUpdatelazy(lazy[node], x, sl, sr);
      vis[node] = true;
      eval(node, sl, sr);
      return;
    }
    _update(2 * node, sl, (sl + sr) / 2, ql, qr, x);
    _update(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr, x);
  }

  T get(int ql, int qr) { return _get(1, 0, N - 1, ql, qr); }
  T _get(int node, int sl, int sr, int ql, int qr)
  {
    if (node < 0 || tree_size <= node || sr < ql || qr < sl)
      return def;

    eval(node, sl, sr);

    if (ql <= sl && sr <= qr)
      return tree[node];

    return __getFun(_get(2 * node, sl, (sl + sr) / 2, ql, qr),
                    _get(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr));
  }
};

int main()
{
  int n, Q, com, l, r, x;
  cin >> n >> Q;
  LazySegmentTree<long long> lst(n, vector<long long>(n, 0), false, 0);
  while (Q--)
  {
    cin >> com >> l >> r;
    if (com == 0)
    {
      cin >> x;
      lst.update(l - 1, r - 1, x);
    }
    else
      cout << lst.get(l - 1, r - 1) << endl;
  }
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
