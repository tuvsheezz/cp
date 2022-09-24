#include <bits/stdc++.h>
using namespace std;
#define N 100000
int main()
{
    long long n, s = 0, r;
    cin >> n;
    vector<long long> a(N + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        a[r]++;
    }
    for (int i = 0; i <= N; i++)
    {
        if (i != N - i)
            s += (a[i] * a[N - i]);
    }
    s = s / 2 + a[N / 2] * (a[N / 2] - 1) / 2;
    cout << s << endl;
    return 0;
}
