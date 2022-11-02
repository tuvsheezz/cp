#include <bits/stdc++.h>
using namespace std;

long long x10(string N)
{
    long long res = 0;
    for (int i = 0; i < N.size(); ++i)
    {
        res = res * 8 + int(N[i] - '0');
    }
    return res;
}
string x9(long long N)
{
    if (N == 0)
        return "0";

    string res;
    while (N > 0)
    {
        res = char(N % 9 + '0') + res;
        N /= 9;
    }
    return res;
}

int main()
{
    string N;
    int K;
    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        N = x9(x10(N));
        for (int j = 0; j < N.size(); ++j)
        {
            if (N[j] == '8')
                N[j] = '5';
        }
    }
    cout << N << endl;
    return 0;
}
