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
LL ssize(STR s)
{
	ret(LL) s.size();
}
template <class T>
T rd()
{
	T n;
	cin >> n;
	ret n;
}
template <class T>
V<T> rv(T n)
{
	V<T> a(n, 0);
	rep(i, n) { cin >> a[i]; }
	ret a;
}
template <class T>
LL vsum(V<T> v)
{
	T s = 0;
	rep(i, (LL)v.size()) { s += v[i]; }
	ret s;
}

template <class T>
struct Geo
{
	T distance_by_coordinates(T x1, T y1, T x2, T y2)
	{
		return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Geo<DD> geo;
	DD x1 = rd<DD>(), y1 = rd<DD>(), x2 = rd<DD>(), y2 = rd<DD>(), x3 = rd<DD>(), y3 = rd<DD>();
	DD a = geo.distance_by_coordinates(x1, y1, x2, y2);
	DD b = geo.distance_by_coordinates(x3, y3, x2, y2);
	DD c = geo.distance_by_coordinates(x1, y1, x3, y3);
	DD p = (a + b + c) / 2.0;
	DD s = sqrt(p * (p - a) * (p - b) * (p - c));

	prd(s);
	Ret;
}
