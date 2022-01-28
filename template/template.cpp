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
LL ssize(STR s)
{
  ret(LL) s.size();
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

LL euler_phi(LL n)
{
  LL res = n, i = 2;
  while (i * i <= n)
  {
    if (n % i == 0)
    {
      res = res / i * (i - 1);
      while (n % i == 0)
      {
        n /= i;
      }
    }
    i++;
  }
  if (n > 1)
  {
    res--;
  }
  ret res;
}

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

// Sieve of Eratosthenes
struct Sieve
{
  V<LL> f, primes;
  void init(int n)
  {
    f.resize(n + 1, 0);
    f[0] = f[1] = -1;
    repa(i, 2, n + 1)
    {
      if (f[i] > 0)
        continue;
      primes.PB(i);
      f[i] = i;
      for (LL j = i * i; j <= n; j += i)
      {
        if (f[j] == 0)
          f[j] = i;
      }
    }
  }
  bool is_prime(LL n) { ret f[n] == n; }
  V<LL> prime_factors(LL n)
  {
    V<LL> r;
    while (n != 1)
    {
      r.PB(f[n]);
      n /= f[n];
    }
    ret r;
  }
  V<PLL> prime_factors_count(LL n)
  {
    V<LL> l = prime_factors(n);
    if (l.size() == 0)
      ret{};
    V<PLL> r(1, MP(l[0], 0));
    repauto(x, l)
    {
      if (r.back().F == x)
        r.back().S++;
      else
        r.emplace_back(x, 1);
    }
    ret r;
  }
};

// combinatorics
V<LL> inv(MAX_N), fact(MAX_N), finv(MAX_N);
void set_inv(LL mod)
{
  inv[1] = 1;
  repa(i, 2, MAX_N) { inv[i] = mod - ((mod / i) * inv[mod % i]) % mod; }
}
void set_fact(LL mod)
{
  set_inv(mod);
  fact[0] = 1;
  finv[0] = 1;
  repa(i, 1, MAX_N)
  {
    fact[i] = (fact[i - 1] * i) % mod;
    finv[i] = (finv[i - 1] * inv[i]) % mod;
  }
}

LL combination(LL n, LL k, LL mod)
{
  LL c = (((fact[n] * finv[k]) % mod) * finv[n - k]) % mod;
  ret c;
}

LL combination2(LL n, LL k, LL mod)
{
  LL c = 1;
  repa(i, n - k, n)
  {
    c = (c * (i + 1)) % mod;
  }
  ret(c * finv[k]) % mod;
}

LL big_pow(LL x, LL n, LL mod)
{
  x = x % mod;
  if (x == 0)
    ret 0;
  if (n == 0)
    ret 1;
  LL z = big_pow(x * x % mod, n / 2, mod);
  if (n & 1)
    z = z * x % mod;
  ret z;
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

LL single_fact(LL n, LL mod)
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

V<pair<char, LL>> run_length_encoding(STR s)
{
  LL n = (LL)s.size();
  V<pair<char, LL>> rle;
  char pre = s[0];
  LL count = 1;
  repa(i, 1, n)
  {
    if (pre != s[i])
    {
      rle.PB({pre, count});
      pre = s[i];
      count = 1;
    }
    else
      count++;
  }
  rle.PB(MP(pre, count));
  ret rle;
}

struct Treap
{
  LL len, ADD = 1000010, MAXVAL = 1000000010;
  unordered_map<LL, LL> mp; /// Change to LL if only LL in treap
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

// LIS<LL>(a, false) ntr gej hereglene shu!
template <typename T>
size_t LIS(const V<T> &a, bool strict)
{
  V<T> lis;
  for (auto &p : a)
  {
    typename V<T>::iterator it;
    if (strict)
      it = lower_bound(begin(lis), end(lis), p);
    else
      it = upper_bound(begin(lis), end(lis), p);
    if (end(lis) == it)
      lis.emplace_back(p);
    else
      *it = p;
  }
  return lis.size();
}

// BIT全検索
// repa(i, 0, 1 << n) {
// 000001 -> 111111
//   repa(j, 0, n) {
//     if(i >> j & 1) {
//         1? 0?
//     }
//   }
// }

// 尺取り法
// rep(i, n)　// ehnii pointer-oo arraygiin buh elementeer
// {
//   while (ss < k && j < n) // 2 dah pointer-oo ugugdsun nuhtsuliig hangah hurtel
//   {
//     ss += a[j++];
//   }
//   if (ss < k) // buh element-g oruulsan ch nuhtsul biylehgui uyd
//     break;
//   ans += n - j + 1; // nuhtsul hangasan hesguudiig hadgalaad
//   ss -= a[i]; // yg odoo baigaa range-iinhee hamgiin ehnii elementiig hasaad ahiad daraagiinh ruu
// }

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

void solve()
{
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(T);
  while (T--)
  {
    solve();
  }
  Ret;
}
