#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

#define MAXN 3002002
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
    initFacts(mod);
    long long a, b;
    cin >> a >> b;

    if ((2 * a - b) % 3 != 0 || (2 * b - a) % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    long long aa = (2 * a - b) / 3, bb = (2 * b - a) / 3;
    cout << nCk(aa + bb, aa, mod) << endl;
    return 0;
}
