#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using IS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;
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

// F -> asc, S -> desc
bool comp(PLL &p1, PLL &p2)
{
	if (p1.F > p2.F)
		ret false;
	else if (p1.F < p2.F)
		ret true;
	else
		ret p1.S > p2.S;
}

struct Treap
{
	LL len, ADD = 1000010, MAXVAL = 1000000010;
	unordered_map<LL, LL> mp;
	IS<LL> T;

	Treap() { len = 0, T.clear(), mp.clear(); }
	void clear() { len = 0, T.clear(), mp.clear(); }

	void insert(LL x)
	{
		len++, x += MAXVAL;
		LL c = mp[x]++;
		T.insert((x * ADD) + c);
	}

	void erase(LL x)
	{
		x += MAXVAL;
		LL c = mp[x];
		if (c)
		{
			c--, mp[x]--, len--;
			T.erase((x * ADD) + c);
		}
	}

	/// 1-based index, returns the K'th element in the treap, -1 if none exists
	LL kth(LL k)
	{
		if (k < 1 || k > len)
			return -1;
		auto it = T.find_by_order(--k);
		return ((*it) / ADD) - MAXVAL;
	}

	/// Count of value < x in treap
	LL count(LL x)
	{
		x += MAXVAL;
		LL c = mp[--x];
		return (T.order_of_key((x * ADD) + c));
	}

	/// Number of elements in treap
	LL size() { return len; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL rd(n);
	LL ans = 0;
	Treap q;
	V<PLL> a(n, MP(0, 0));
	rep(i, n) { cin >> a[i].F; }
	rep(i, n) { cin >> a[i].S; }

	sort(a.begin(), a.end(), comp);

	LL j = 0;
	rep(i, n)
	{
		while (j < n && a[j].F == a[i].F && a[j].S == a[i].S)
		{
			q.insert(a[j].S);
			j++;
		}

		auto cnt = q.count(a[i].S);
		ans += j - cnt;
	}
	pr(ans);
	PN;
	Ret;
}
