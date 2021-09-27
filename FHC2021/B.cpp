#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++)
  {
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    if (A < n + m - 1 || (n + m - 1) * 1000 < A || B < n + m - 1 || (n + m - 1) * 1000 < B)
    {
      cout << "Case #" << cs << ": Impossible\n";
      continue;
    }
    cout << "Case #" << cs << ": Possible\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i == n - 1 && j == 0)
          cout << B - (m + n - 2) << " ";
        else if (i == n - 1 && j == m - 1)
          cout << A - (m + n - 2) << " ";
        else
          cout << "1 ";
      }
      cout << '\n';
    }
  }
  return 0;
}
