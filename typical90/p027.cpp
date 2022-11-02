#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<string> st;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (st.find(s) == st.end())
            cout << i << endl;
        st.insert(s);
    }
    return 0;
}
