#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  vector<int> g = {0, 0, 1, 2};
  int N = g.size();
  vector<int> r;

  int devs = 0, socks = 1;
  for (int i = 0; i < N; i++)
    if (g[i] == 0)
      ++devs;
    else
      socks += g[i] - 1;

  if (socks < devs)
  {
    cout << "NG";
    return 0;
  }

  vector<int> s;
  s.push_back(N);
  r.assign(N, -1);
  int k = 0;

  for (int i = 0; i < N && s.size() - k < devs; i++)
    if (g[i] > 1)
    {
      r[i] = s[k++];
      for (int j = 0; j < g[i]; j++)
        s.push_back(i);
    }

  for (int i = 0; i < N; i++)
    if (g[i] == 0)
      r[i] = s[k++];

  for (auto x : r)
    cout << x << " ";

  return 0;
}

#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PlugStuffIn
{
public:
  vector<int> plug(vector<int>);
};

vector<int> PlugStuffIn::plug(vector<int> g)
{
  int n = g.size();
  queue<int> con;
  con.push(n);

  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++)
  {
    if (g[i] != 0)
    {
      ans[i] = con.front();
      con.pop();
      for (int j = 0; j < g[i]; j++)
        con.push(i);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (g[i] == 0)
    {
      if (con.empty())
      {
        return {};
      }
      ans[i] = con.front();
      con.pop();
    }
  }
  return ans;
}

class PlugStuffIn
{
public:
  vector<int> plug(vector<int> gadgets)
  {
    int n = gadgets.size(), devices = 0;
    vector<int> ret(n, -1);
    queue<int> q;
    q.push(n);
    for (int i = 0; i < n; i++)
    {
      if (gadgets[i] == 0)
      {
        devices++;
      }
      else
      {
        int x = q.front();
        q.pop();
        ret[i] = x;
        for (int j = 0; j < gadgets[i]; j++)
        {
          q.push(i);
        }
      }
