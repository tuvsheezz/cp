#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, k, ans = 0, cur = 0;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int j = 0;

  for (int i = 0; i < n; i++)
  {
    while (j < n && cur + a[j] <= k)
    {
      cur += a[j];
      j++;
    }
    ans += j - i;
    cur -= a[i];
  }
  cout << ans << '\n';
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cl
