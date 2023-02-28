#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<int> parent, size;
  int size_max = 0, count;

  UnionFind(int n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    count = n;
    size_max = 1;
  }

  int root(int x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    size_max = max(size[x], size_max);
    count--;
  }
  int count_of_sets() { return count; }
  int get_union_size(int x) { return size[root(x)]; }
};

int main()
{
  int n, Q, com, x, y;
  cin >> n >> Q;
  UnionFind uf(n);
  while (Q--)
  {
    cin >> com >> x >> y;
    if (com == 0)
      uf.unite(x, y);
    else
      cout << uf.same(x, y) << '\n';
  }
  return 0;
}
