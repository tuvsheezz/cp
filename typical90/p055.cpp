#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, p, q, ans = 0;
    cin >> n >> p >> q;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        for (long long j = i + 1; j < n; j++)
            for (long long k = j + 1; k < n; k++)
                for (long long l = k + 1; l < n; l++)
                    for (long long m = l + 1; m < n; m++)
                    {
                        int x = a[i] % p * a[j] % p * a[k] % p * a[l] % p * a[m] % p;
                        if (x == q)
                            ans++;
                    }
    cout << ans << endl;
    return 0;
}
