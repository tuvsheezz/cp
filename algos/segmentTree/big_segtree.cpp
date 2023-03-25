#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
  int left, right;
  int maxi = INT32_MIN;
  SegTree *left_child = nullptr, *right_child = nullptr;

  SegTree(int lb, int rb)
  {
    left = lb;
    right = rb;
  }

  void extend()
  {
    if (!left_child && left + 1 < right)
    {
      int t = (left + right) / 2;
      left_child = new SegTree(left, t);
      right_child = new SegTree(t, right);
    }
  }

  void set(int k, int x)
  {
    extend();
    maxi = max(x, maxi);
    if (left_child)
    {
      if (k < left_child->right)
        left_child->set(k, x);
      else
        right_child->set(k, x);
    }
  }

  int get_max(int lq, int rq)
  {
    if (lq <= left && right <= rq)
      return maxi;
    if (max(left, lq) >= min(right, rq))
      return INT32_MIN;
    extend();
    return max(left_child->get_max(lq, rq), right_child->get_max(lq, rq));
  }
};

int main()
{
  int n, m, u, v;
  int mod = 1000000007;
  cin >> n;
  SegTree st(0, mod);
  for (int i = 0; i < n; i++)
  {
    cin >> u;
    auto x = st.get_max(u + 1, mod);
    st.set(u, i + 1);
    cout << (x == INT32_MIN ? -1 : x) << " \n"[i == n - 1];
  }
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bh