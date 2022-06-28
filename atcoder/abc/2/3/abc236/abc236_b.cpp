#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0, x;
	cin >> n;
	for (int i = 0; i < 4 * n - 1; i++)
	{
		cin >> x;
		ans ^= x;
	}
	cout << ans << '\n';
	return 0;
}
