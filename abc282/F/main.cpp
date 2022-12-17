#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4000, x = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 4000; j += 2)
            if (i + j < n)
                x++;
    }
    prn(x);
}
