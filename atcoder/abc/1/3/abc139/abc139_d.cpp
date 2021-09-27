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

struct MYM
{
  DD distance_between_2_points(DD x1, DD y1, DD x2, DD y2) { ret sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
  DD area_of_triangle_with_3_sides(DD a, DD b, DD c) { ret sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c)) / 4.0; }
};

struct UnionFind
{
  V<LL> parent, size;
  LL size_max = 0, count;

  void init(LL n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    count = n;
    size_max = 1;
  }
  LL root(LL x) { ret parent[x] == -1 ? x : parent[x] = root(parent[x]); }
  bool same(LL x, LL y) { ret root(x) == root(y); }
  void unite(LL x, LL y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      ret;

    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    size_max = max(size[x], size_max);
    count--;
  }
  LL count_of_sets() { ret count; }
  LL get_union_size(LL x) { ret size[root(x)]; }
};

template <class T>
T fsum(T a, T b) { ret a + b; }
template <class T>
T fmin(T a, T b) { ret min(a, b); }
template <class T>
T fmax(T a, T b) { ret max(a, b); }
template <class T>
T fxor(T a, T b) { ret a ^ b; }
template <class T, class D>
struct SegmentTree
{
  V<D> tree;
  T tree_size, N;
  D def;
  D(*ope)
  (D, D);

  void init(T n, V<D> a, D (*op)(D, D), bool set_parent = true, D v = 0)
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

LL big_pow(LL x, LL n, LL mod)
{
  if (n == 0)
    ret 1;
  LL z = big_pow(x * x % mod, n / 2, mod);
  if (n & 1)
    z = z * x % mod;
  ret z;
}

vector<bool> is_prime(MAX_N, true);
V<LL> prime_numbers;

void prepare_prime_numbers()
{
  is_prime[0] = false;
  is_prime[1] = false;
  repa(i, 2, MAX_N + 1)
  {
    if (!is_prime[i])
      continue;
    LL mult = 2;
    while (i * mult <= MAX_N)
    {
      is_prime[i * mult] = false;
      mult++;
    }
  }
  repa(i, 0, MAX_N + 1)
  {
    if (is_prime[i])
      prime_numbers.push_back(i);
  }
}

bool is_prime_simple(LL n)
{
  if (n == 1)
    ret false;
  for (LL i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      ret false;
  }
  ret true;
}

V<LL> prime_divisors(LL n)
{
  V<LL> res;
  LL tmp = n;
  for (auto const &x : prime_numbers)
  {
    if (x * x > n)
      break;
    while (n % x == 0)
    {
      res.push_back(x);
      n /= x;
    }
  }
  if (n > 1)
    res.push_back(n);
  sort(res.begin(), res.end());
  ret res;
}

LL fact(LL n, LL mod)
{
  LL r = 1;
  if (n < 2)
    ret r;
  repa(i, 1, n + 1)
  {
    r = (r * i) % mod;
  }
  ret r;
}

// BIT全検索
// repa(i, 0, 1 << (n - 1)) {
// 000001 -> 111111
//   repa(j, 0, n + 1) {
//     if(i >> j & 1) {
//         1? 0?
//     }
//   }
// }

void solve()
{
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL T = rd<LL>();
  pr(T * (T - 1) / 2);
  PN;
  Ret;
}
