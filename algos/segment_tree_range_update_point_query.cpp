#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> xxx(pair<long long, long long> a, pair<long long, long long> b)
{
  if (a.second > b.second)
    return a;
  else
    return b;
}

template <class T>
struct SegmentTree
{
  vector<T> tree;
  int tree_size, N;
  T def;

  SegmentTree(int n, T v)
  {
    while (__builtin_popcount(n) != 1)
    {
      n++;
    }
    tree_size = 2 * n;
    tree.resize(tree_size, v);

    N = n;
    def = v;
  }
  // [ql, qr]
  void update_range(int ql, int qr, T v) { _update_range(1, 0, N - 1, ql, qr, v); }
  void _update_range(int node, int sl, int sr, int ql, int qr, T v)
  {
    if (ql <= sl && sr <= qr)
    {
      tree[node] = v;
      return;
    }
    if (sr < ql || qr < sl)
      return;
    _update_range(2 * node, sl, (sl + sr) / 2, ql, qr, v);
    _update_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr, v);
  }

  T get_point(int ind)
  {
    T x = tree[ind += N];
    while (ind / 2 >= 1)
    {
      ind /= 2;
      x = xxx(tree[ind], x);
    }
    return x;
  }
};

int main()
{
  int n, Q, com, l, r, x;
  cin >> n >> Q;
  SegmentTree<pair<long long, long long>> st(n, {INT32_MAX, -1});
  for (int i = 0; i < Q; i++)
  {
    cin >> com;
    if (com == 0)
    {
      cin >> l >> r >> x;
      st.update_range(l, r, {x, i});
    }
    else if (com == 1)
    {
      cin >> x;
      cout << st.get_point(x).first << '\n';
    }
  }
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D