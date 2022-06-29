#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXN 2222

long long fact[MAXN], invfact[MAXN], inv[MAXN];
void initFacts(long long m)
{
  fact[0] = 1;
  invfact[0] = 1;
  inv[0] = 1;
  inv[1] = 1;

  for (int i = 1; i < MAXN; i++)
    fact[i] = (fact[i - 1] * i) % m;
  for (int i = 2; i < MAXN; i++)
    inv[i] = (-inv[m % i] * (m / i) % m + m) % m;
  for (int i = 1; i < MAXN; i++)
    invfact[i] = invfact[i - 1] * inv[i] % m;
}

long long nCk(long long n, long long k, long long m)
{
  if (k > n || k < 0)
    return 0;
  if (k == 0)
    return 1;
  return (((fact[n] * invfact[k]) % m) * invfact[n - k]) % m;
}

int main()
{
  ll n, k;
  cin >> n >> k;
  initFacts(mod);
  for (int i = 0; i < k; i++)
    cout << (nCk(n - k + 1, i + 1, mod) * nCk(k - 1, i, mod)) % mod << endl;
  return 0;
}
