#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, ans = 0;
  cin >> n;
  stack<int> st;
  for (int i = 1; i <= n; i++)
  {
    int t;
    cin >> t;
    if (t != i)
      continue;
    if (!st.empty() && st.top() == t - 1)
    {
      ans++;
      st.pop();
    }
    else
      st.push(t);
  }
  cout << ans + st.size() << '\n';
  return 0;
}
