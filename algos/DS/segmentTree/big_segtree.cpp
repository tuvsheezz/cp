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
    return left_child->get_max(lq, rq) + right_child->get_max(lq, rq);
  }
};

int main()
{
  int n, q;
  int mod = 1000000007;
  SegTree st(-mod, mod);
  cin >> n;

  vector<int> x(n), p(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    st.set(x[i], p[i]);

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << st.get_max(l, r + 1) << endl;
  }

  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bh