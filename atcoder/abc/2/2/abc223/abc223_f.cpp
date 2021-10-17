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

pair<PLL, LL> fbra(pair<PLL, LL> a, pair<PLL, LL> b)
{
	// (3, 2)  (3, 3)-> )))(( + )))(( = ))))((]
	if (a.S == 1 && b.S == 1)
		return MP(MP(0, 0), 1);
	if (a.F.S >= b.F.F)
	{
		a.F.S -= b.F.F;
		b.F.F = 0;
	}
	else
	{
		b.F.F -= a.F.S;
		a.F.S = 0;
	}

	LL x = a.F.F + b.F.F;
	LL y = a.F.S + b.F.S;

	if (x == 0 && y == 0)
		return MP(MP(0, 0), 1);
	else
		return MP(MP(x, y), 0);
}

template <class T, class D>
struct SegmentTree
{
	V<D> tree;
	T tree_size, N;
	D def;
	D(*ope)
	(D, D);

	void init(T n, V<D> a, D (*op)(D, D), bool set_parent, D v)
	{
		while (__builtin_popcount(n) != 1)
		{
			a.PB(v);
			n++;
		}
		tree.resize(2 * n, v);
		tree_size = 2 * n;
		N = n;
		def = v;
		ope = op;
		rep(i, n) { tree[n + i] = a[i]; }
		if (set_parent)
			repd(i, n - 1, 1) { tree[i] = ope(tree[2 * i], tree[2 * i + 1]); }
	}

	D get_range(T ql, T qr) { ret _get_range(1, 0, N - 1, ql, qr); }
	D _get_range(T node, T sl, T sr, T ql, T qr)
	{
		if (ql <= sl && sr <= qr)
			ret tree[node];
		if (sr < ql || qr < sl)
			ret def;
		ret ope(_get_range(2 * node, sl, (sl + sr) / 2, ql, qr), _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr));
	}
	void update_range(T ql, T qr, D v) { _update_range(1, 0, N - 1, ql, qr, v); }
	void _update_range(T node, T sl, T sr, T ql, T qr, D v)
	{
		if (ql <= sl && sr <= qr)
		{
			tree[node] = ope(tree[node], v);
			ret;
		}
		if (sr < ql || qr < sl)
			ret;
		_update_range(2 * node, sl, (sl + sr) / 2, ql, qr, v);
		_update_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr, v);
	}

	void update_node(T ind, D val)
	{
		tree[ind += N] = val;
		while (ind / 2 >= 1)
		{
			ind /= 2;
			tree[ind] = ope(tree[2 * ind], tree[2 * ind + 1]);
		}
	}
	D get_leaf(LL x) { ret tree[x + N]; }
	void check_tree() { rep(i, tree_size) cout << i << ": " << tree[i] << "\n"; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL rd(n, Q);
	V<pair<PLL, LL>> k(n);
	STR rd(s);
	rep(i, n)
	{
		if (s[i] == ')')
			k[i] = MP(MP(1, 0), 0);
		else
			k[i] = MP(MP(0, 1), 0);
	}
	SegmentTree<LL, pair<PLL, LL>> st;
	st.init(n, k, &fbra, true, MP(MP(0, 0), 1));

	while (Q--)
	{
		LL rd(t, l, r);
		l--;
		r--;
		if (t == 1)
		{
			pair<PLL, LL> x = k[l];
			k[l] = k[r];
			k[r] = x;

			st.update_node(l, k[l]);
			st.update_node(r, k[r]);
		}
		else
		{
			if (st.get_range(l, r).S == 1)
				Yes;
			else
				No;
		}
	}
	Ret;
}
