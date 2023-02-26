#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix_sum(vector<long long> &a)
{
  vector<long long> b(a.size() + 1, 0);
  for (int i = 0; i < a.size(); i++)
    b[i + 1] = a[i] + b[i];
  return b;
}

int main()
{
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  auto b = prefix_sum(a);
  while (k--)
  {
    long long l, r;
    cin >> l >> r;
    cout << b[r] - b[l - 1] << '\n';
  }
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ai
