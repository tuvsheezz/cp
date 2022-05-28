#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
  vector<pair<long long, long long>> tree;
  long long N, defv;
  void init(vector<long long> a, long long n, long long def, bool set_parent = true)
  {
    N = 1;
    while (N < n)
      N *= 2;
    tree.resize(2 * N, make_pair(def, 1));
    defv = def;

    for (long long i = 0; i < n; i++)
      tree[N + i] = make_pair(a[i], 1);
    if (set_parent)
      for (long long i = N - 1; i >= 1; i--)
      {
        if (tree[2 * i].first == tree[2 * i + 1].first)
          tree[i] = make_pair(tree[2 * i].first, tree[2 * i].second + tree[2 * i + 1].second);
        else if (tree[2 * i].first > tree[2 * i + 1].first)
          tree[i] = tree[2 * i + 1];
        else
          tree[i] = tree[2 * i];
      }
  }

  void update_point(long long i, long long v)
  {
    tree[i += N] = make_pair(v, 1);
    while (i / 2 >= 1)
    {
      i /= 2;
      if (tree[2 * i].first == tree[2 * i + 1].first)
        tree[i] = make_pair(tree[2 * i].first, tree[2 * i].second + tree[2 * i + 1].second);
      else if (tree[2 * i].first > tree[2 * i + 1].first)
        tree[i] = tree[2 * i + 1];
      else
        tree[i] = tree[2 * i];
    }
  }

  pair<long long, long long> get_range(long long ql, long long qr) { return _get_range(1, 0, N - 1, ql, qr); }
  pair<long long, long long> _get_range(long long node, long long sl, long long sr, long long ql, long long qr)
  {
    if (ql <= sl && sr <= qr)
      return tree[node];
    if (sr < ql || qr < sl)
      return make_pair(defv, 1);
    pair<long long, long long> p = _get_range(2 * node, sl, (sl + sr) / 2, ql, qr);
    pair<long long, long long> q = _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr);
    if (p.first == q.first)
      return make_pair(q.first, q.second + p.second);
    else if (p.first > q.first)
      return q;
    else
      return p;
  }

  void check_tree()
  {
    for (auto &x : tree)
      cout << x.first << ": " << x.second << " ";
    cout << '\n';
  }
};

int main()
{
  long long n, Q;
  cin >> n >> Q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  SegmentTree st;
  st.init(a, n, 1LL << 60, true);
  while (Q--)
  {
    long long com, x, y;
    cin >> com >> x >> y;
    if (com == 1)
      st.update_point(x, y);
    else
      cout << st.get_range(x, y - 1).first << " " << st.get_range(x, y - 1).second << "\n";
  }
  return 0;
}