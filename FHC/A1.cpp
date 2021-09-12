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
    int L;
    string S;
    bool fx = true, fo = true;
    int cx = 0, co = 0;
    cin >> L >> S;
    for (int i = 0; i < L; i++)
    {
      if (S[i] == 'F')
        continue;
      else if (S[i] == 'X')
      {
        if (fx == false)
        {
          cx++;
          fx = !fx;
        }
        if (fo == true)
        {
          co++;
          fo = !fo;
        }
      }
      else
      {
        if (fx == true)
        {
          cx++;
          fx = !fx;
        }
        if (fo == false)
        {
          co++;
          fo = !fo;
        }
      }
    }
    cout << "Case #" << cs << ": " << min(co, cx) << '\n';
  }
  return 0;
}
