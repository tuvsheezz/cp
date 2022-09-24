#include <bits/stdc++.h>
using namespace std;

struct Matrix
{
    vector<vector<long long>> m;
    Matrix(int row, int col) { m.resize(row, vector<long long>(col, 0)); }
};

Matrix MatrixMultification(Matrix A, Matrix B, long long m)
{
    Matrix C(A.m.size(), B.m[0].size());
    for (int i = 0; i < (int)A.m.size(); i++)
        for (int j = 0; j < (int)B.m[0].size(); j++)
            for (int k = 0; k < (int)B.m.size(); k++)
                C.m[i][j] = (C.m[i][j] + A.m[i][k] * B.m[k][j]) % m;
    return C;
}

Matrix matrix_pow(Matrix A, long long b, long long mod)
{
    Matrix r(A.m.size(), A.m.size());
    for (int i = 0; i < (int)A.m.size(); i++)
        r.m[i][i] = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            r = MatrixMultification(r, A, mod);
        b /= 2;
        A = MatrixMultification(A, A, mod);
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Matrix a(3, 3), c(3, 1);
    a.m[0][0] = 1, a.m[0][1] = 1, a.m[0][2] = 1;
    a.m[1][0] = 1, a.m[1][1] = 0, a.m[1][2] = 0;
    a.m[2][0] = 0, a.m[2][1] = 1, a.m[2][2] = 0;

    c.m[0][0] = 2;
    c.m[1][0] = 1;
    c.m[2][0] = 1;

    long long b;
    cin >> b;
    auto y = matrix_pow(a, b - 3, 1000000007);
    auto x = MatrixMultification(y, c, 1000000007);
    cout << x.m[0][0] << endl;
    return 0;
}
