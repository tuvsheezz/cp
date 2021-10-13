#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884L
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define MLL map<LL, LL>
#define MSL map<STR, LL>
#define MLB map<LL, bool>
#define PQA priority_queue<LL, V<LL>, greater<LL>>
#define PQD priority_queue<LL, V<LL>, less<LL>>
#define IT iterator
#define F first
#define S second
#define PB push_back
#define PLL pair<LL, LL>
#define MP make_pair
#define rep(i, e) for (LL i = 0; i < e; i++)
#define repa(i, s, e) for (LL i = s; i < e; i++)
#define repd(i, s, e) for (LL i = s; i >= e; i--)
#define repauto(x, s) for (auto x : s)
#define rd(...) \
	__VA_ARGS__;  \
	read(__VA_ARGS__)
#define rdv(value, ...) \
	value(__VA_ARGS__);   \
	cin >> value
template <class T>
auto &operator>>(istream &is, vector<T> &xs)
{
	for (auto &x : xs)
		is >> x;
	return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> &xs)
{
	int sz = xs.size();
	rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
	return os;
}
template <class T, class Y>
auto &operator<<(ostream &os, pair<T, Y> &xs)
{
	os << "{" << xs.first << ", " << xs.second << "}";
	return os;
}
template <class T, class Y>
auto &operator>>(istream &is, vector<pair<T, Y>> &xs)
{
	for (auto &[x1, x2] : xs)
		is >> x1 >> x2;
	return is;
}
template <class... Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prd(x) cout << fixed << setprecision(50) << x
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

bool comp(pair<DD, LL> p1, pair<DD, LL> p2)
{
	if (p1.first < p2.first)
		return false;
	if (p1.first > p2.first)
		return true;
	return p1.second < p2.second;
}

LL janjan(char x, char y)
{
	if (x == y)
		return 0;
	if (x == 'G' && y == 'P')
		ret 1;
	if (x == 'P' && y == 'C')
		ret 1;
	if (x == 'C' && y == 'G')
		ret 1;
	return 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL rd(n, m);
	n *= 2;
	V<STR> sh(n);
	V<pair<DD, LL>> sc(n);
	repa(i, 0, n) { cin >> sh[i]; }
	rep(i, n)
	{
		sc[i] = MP(0.0, i);
	}

	rep(j, m)
	{
		for (LL i = 0; i < n - 1; i += 2)
		{
			if (janjan(sh[sc[i].second][j], sh[sc[i + 1].second][j]) == 0)
			{
				sc[i].first += 0;
				sc[i + 1].first += 0;
			}
			else if (janjan(sh[sc[i].second][j], sh[sc[i + 1].second][j]) == 2)
			{
				sc[i].first += 1.0;
			}
			else
				sc[i + 1].first += 1.0;
		}
		sort(sc.begin(), sc.end(), comp);
	}
	rep(i, n)
	{
		pr(sc[i].second + 1);
		PN;
	}
	Ret;
}
