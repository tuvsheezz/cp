#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
struct BIT
{
    int N;
    vector<T> bit;
    void init(int n)
    {
        N = n;
        bit.resize(n + 1, 0);
    }

    void add(int i, T x)
    {
        i++;
        while (i <= N)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    T sum(int i)
    {
        T ans = 0;
        while (i > 0)
        {
            ans += bit[i];
            i -= i & -i;
        }
        return ans;
    }
    T sum(int L, int R) { return sum(R) - sum(L); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q = 0, x;
    BIT<ll> A;
    cin >> n;
    vector<ll> b(n), c(n);
    A.init(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b[i] = x;
        q += A.sum(x, n);
        A.add(x, 1);
        c[i] = n - 1 - x;
    }
    for (int i = 0; i < n; i++)
    {
        cout << q << endl;
        q += c[i] - b[i];
    }

    return 0;
}
