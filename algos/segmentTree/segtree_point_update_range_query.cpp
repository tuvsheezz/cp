#include <bits/stdc++.h>
using namespace std;

template <class T>
struct SegmentTree
{
  vector<T> tree;
  int tree_size, N;
  T def;

  T stFun(T a, T b) { return max(a, b); }

  SegmentTree(int n, vector<T> a, bool set_parent = true, T v = 0)
  {
    while (__builtin_popcount(n) != 1)
    {
      a.push_back(v);
      n++;
    }
    tree_size = 2 * n;
    tree.resize(tree_size, v);

    N = n;
    def = v;

    for (int i = 0; i < n; i++)
      tree[n + i] = a[i];

    if (set_parent)
      for (int i = n - 1; i >= 1; i--)
        tree[i] = stFun(tree[2 * i], tree[2 * i + 1]);
  }
  // [ql, qr]
  T get_range(int ql, int qr) { return _get_range(1, 0, N - 1, ql, qr); }
  T _get_range(int node, int sl, int sr, int ql, int qr)
  {
    if (ql <= sl && sr <= qr)
      return tree[node];
    if (sr < ql || qr < sl)
      return def;

    return stFun(_get_range(2 * node, sl, (sl + sr) / 2, ql, qr),
                 _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr));
  }

  void update_node(int ind, T val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      tree[ind] = stFun(tree[2 * ind], tree[2 * ind + 1]);
    }
  }

  void check_tree()
  {
    for (int i = 0; i < tree_size; i++)
      cout << i << ": " << tree[i] << "\n";
  }

  T get_leaf(int x) { return tree[x + N]; }
};

int main()
{
  int n, Q, com, x, y;
  cin >> n >> Q;
  SegmentTree<long long> st(n, vector<long long>(n, 0LL), true, 0);

  while (Q--)
  {
    cin >> com >> x >> y;
    if (com == 1)
      st.update_node(x - 1, y);
    else
      cout << st.get_range(x - 1, y - 2) << endl;
  }

  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bf