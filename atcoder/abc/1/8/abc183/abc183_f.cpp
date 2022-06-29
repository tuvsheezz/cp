#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<long long> parent, size;
  vector<map<long long, long long>> c;
  void init(long long n, vector<long long> &a)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    c.resize(n);
    for (int i = 0; i < n; i++)
      c[i][a[i]] = 1;
  }
  long long root(long long x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
  bool same(long long x, long long y) { return root(x) == root(y); }
  void unite(long long x, long long y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    for (auto &cc : c[y])
      c[x][cc.first] += cc.second;
  }
  long long getc(long long u, long long cl)
  {
    long long x = root(u);
    if (c[x].find(cl) == c[x].end())
      return 0;
    else
      return c[x][cl];
  }
};

int main()
{
  long long n, Q, com, x, y;
  cin >> n >> Q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  UnionFind uf;
  uf.init(n, a);

  while (Q--)
  {
    cin >> com >> x >> y;
    if (com == 1)
    {
      if (!uf.same(x - 1, y - 1))
        uf.unite(x - 1, y - 1);
    }
    else
      cout << uf.getc(x - 1, y) << endl;
  }
  return 0;
}
