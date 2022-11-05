#include <bits/stdc++.h>
using namespace std;

bool check(string s, int n)
{
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur == 0 && s[i] == ')')
            return false;
        else if (s[i] == ')')
            cur--;
        else
            cur++;
    }
    return cur == 0;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans;

    for (int i = 0; i < 1 << (n - 1); i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                s += '(';
            else
                s += ')';
        }
        if (check(s, n))
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    for (auto &q : ans)
        cout << q << endl;
    return 0;
}
