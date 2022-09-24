#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    long long other = 0;
    for (int a = 1; a <= N; a++)
    {
        for (int b = max(1, a - (K - 1)); b <= min(N, a + (K - 1)); b++)
        {
            for (int c = max(1, a - (K - 1)); c <= min(N, a + (K - 1)); c++)
            {
                if (abs(b - c) <= K - 1)
                    other += 1;
            }
        }
    }
    cout << (long long)N * N * N - other << endl;
    return 0;
}