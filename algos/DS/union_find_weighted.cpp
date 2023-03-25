#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct WeightedUnionFind
{
  vector<int> parent, size, rank;
  int size_max, count;
  vector<T> wd;
  WeightedUnionFind(int n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    rank.resize(n, 0);
    count = n;
    size_max = 1;
    wd.resize(n, 0);
  }

  int root(int x)
  {
    if (parent[x] == -1)
      return x;
    else
    {
      int parent_x = root(parent[x]);
      wd[x] += wd[parent[x]];
      return parent[x] = parent_x;
    }
  }

  bool same(int x, int y) { return root(x) == root(y); }

  T weight(int x)
  {
    root(x);
    return wd[x];
  }

  void unite(int x, int y, T w)
  {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (rank[x] < rank[y])
    {
      swap(x, y);
      w = -w;
    }

    parent[y] = x;
    size[x] += size[y];
    rank[x] += (rank[x] == rank[y]);
    wd[y] = w;
    size_max = max(size[x], size_max);
    count--;
  }

  T diff(int x, int y) { return weight(y) - weight(x); }
};

int main()
{
  int n, Q, com, x, y, z;
  cin >> n >> Q;
  WeightedUnionFind<int> uf(n);
  while (Q--)
  {
    cin >> com >> x >> y;
    if (com == 0)
    {
      cin >> z;
      uf.unite(x, y, z);
    }
    else
    {
      if (uf.same(x, y))
        cout << uf.diff(x, y) << '\n';
      else
        cout << "?\n";
    }
  }
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B