#include <bits/stdc++.h>
using namespace std;

template <class T>
struct LazySegmentTree
{
  vector<T> tree, lazy;
  vector<bool> updated;
  int tree_size, N;
  T def;

  LazySegmentTree(int n, vector<T> a, bool set_parent = true, T v = 0)
  {
    while (__builtin_popcount(n) != 1)
    {
      a.push_back(v);
      n++;
    }
    tree_size = 2 * n;

    tree.resize(tree_size, v);
    lazy.resize(tree_size, 0);
    updated.resize(tree_size, false);

    N = n;
    def = v;

    for (int i = 0; i < n; i++)
      tree[n + i] = a[i];

    if (set_parent)
      for (int i = n - 1; i >= 1; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  void eval(int node, int sl, int sr)
  {
    if (updated[node])
    {
      tree[node] += lazy[node];
      if (sr > sl)
      {
        lazy[2 * node] += lazy[node] / 2;
        lazy[2 * node + 1] += lazy[node] / 2;
        updated[2 * node] = true;
        updated[2 * node + 1] = true;
      }

      lazy[node] = 0;
      updated[node] = false;
    }
  }

  void range_update(int ql, int qr, T x) { return _range_update(1, 0, N - 1, ql, qr, x); }
  void _range_update(int node, int sl, int sr, int ql, int qr, T x)
  {
    if (node < 0 || tree_size <= node)
      return;

    eval(node, sl, sr);

    if (sr < ql || qr < sl)
      return;

    if (ql <= sl && sr <= qr)
    {
      lazy[node] += (sr - sl + 1) * x;
      updated[node] = true;
      eval(node, sl, sr);
      return;
    }
    _range_update(2 * node + 0, sl, (sl + sr) / 2 + 0, ql, qr, x);
    _range_update(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr, x);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  T get_range(int ql, int qr) { return _get_range(1, 0, N - 1, ql, qr); }
  T _get_range(int node, int sl, int sr, int ql, int qr)
  {
    if (tree_size <= node || node < 0 || sr < ql || qr < sl)
      return 0;

    eval(node, sl, sr);

    if (ql <= sl && sr <= qr)
      return tree[node];

    return _get_range(2 * node + 0, sl, (sl + sr) / 2, ql, qr) +
           _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr);
  }
};

int main()
{
  int n, Q, com, l, r, x;
  cin >> n >> Q;
  LazySegmentTree<long long> lst(n, vector<long long>(n, 0));
  while (Q--)
  {
    cin >> com >> l >> r;
    if (com == 0)
    {
      cin >> x;
      lst.range_update(l - 1, r - 1, x);
    }
    else
      cout << lst.get_range(l - 1, r - 1) << endl;
  }
  return 0;
}