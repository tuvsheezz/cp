#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<long long> parent, size;
  long long size_max = 0, count;

  UnionFind(long long n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    count = n;
    size_max = 1;
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
    size_max = max(size[x], size_max);
    count--;
  }
  long long count_of_sets() { return count; }
  long long get_union_size(long long x) { return size[root(x)]; }
};

int main()
{

  return 0;
}
