#include <bits/stdc++.h>
using namespace std;

struct Sieve
{
  vector<long long> f, primes;
  Sieve(int n)
  {
    f.resize(n + 1, 0);
    f[0] = f[1] = -1;
    for (long long i = 2; i <= n; i++)
    {
      if (f[i] > 0)
        continue;
      primes.push_back(i);
      f[i] = i;
      for (long long j = i * i; j <= n; j += i)
      {
        if (f[j] == 0)
          f[j] = i;
      }
    }
  }
  bool is_prime(long long n) { return f[n] == n; }

  vector<long long> prime_factors(long long n)
  {
    vector<long long> r;
    while (n != 1)
    {
      r.push_back(f[n]);
      n /= f[n];
    }
    return r;
  }

  vector<pair<long long, long long>> prime_factors_count(long long n)
  {
    vector<long long> l = prime_factors(n);
    if (l.size() == 0)
      return {};
    vector<pair<long long, long long>> r(1, {l[0], 0});
    for (auto &x : l)
    {
      if (r.back().first == x)
        r.back().second++;
      else
        r.emplace_back(x, 1);
    }
    return r;
  }
};

int main()
{
  int Q, n, MAXN = 300300;
  Sieve sv(MAXN);
  cin >> Q;
  while (Q--)
  {
    cin >> n;
    cout << vector<string>({"No", "Yes"})[sv.is_prime(n)] << '\n';
  }
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_z