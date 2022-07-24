#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector q(4, vector<int>(n + 3, -1));
  q[0][0] = q[0][1] = q[1][0] = q[2][1] = 0;
  q[1][1] = q[2][0] = q[3][0] = q[3][1] = 1;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
    {
      if (s[i] == 'o' && q[j][i + 1] == 0)
        q[j][i + 2] = q[j][i];
      if (s[i] == 'o' && q[j][i + 1] == 1)
        q[j][i + 2] = (q[j][i] + 1) % 2;
      if (s[i] == 'x' && q[j][i + 1] == 0)
        q[j][i + 2] = (q[j][i] + 1) % 2;
      if (s[i] == 'x' && q[j][i + 1] == 1)
        q[j][i + 2] = q[j][i];
    }

  for (int i = 0; i < 4; i++)
    if (q[i][0] == q[i][n] && q[i][1] == q[i][n + 1])
    {
      for (int j = 1; j < n + 1; j++)
        cout << ((q[i][j] == 0) ? 'S' : 'W');
      cout << endl;
      return 0;
    }
  cout << -1 << endl;
  return 0;
}
