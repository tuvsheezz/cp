#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i < e; i++)
using namespace std;
int main()
{
    ll n;
    string s;
    cin >> n >> s;
    stack<char> st;
    rep(i, n)
    {
        if (!st.empty() && st.top() == '(' && s[i] == ')')
            st.pop();
        else
            st.push(s[i]);
    }
    cout << (!st.empty() ? "No\n" : "Yes\n");
    return 0;
}
