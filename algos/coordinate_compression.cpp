#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Compression
{
  unordered_map<T, int> coor;
  long long n;

  Compression(vector<T> aa)
  {
    n = aa.size();
    sort(aa.begin(), aa.end());
    int ind = 1;
    for (int i = 0; i < n; i++)
    {
      if (coor.find(aa[i]) != coor.end())
        continue;
      coor[aa[i]] = ind++;
    }
  }

  int query(T val) { return coor[val]; }
};

int main()
{
  long long n;
  cin >> n;
  vector<long long> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  Compression<long long> compre(a);

  for (int i = 0; i < n; i++)
    cout << compre.query(a[i]) << " ";

  cout << '\n';
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o
