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
#define prs(x) cout << x << ' '
#define prn(x) cout << x << '\n'
#define prd() cout << fixed << setprecision(50);
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
  vector<long long> parent, size;
  long long size_max = 0, count;

  UnionFind(long long n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    count = n;
    size_max = 1;
  }

  long long root(long long x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
  bool same(long long x, long long y) { return root(x) == root(y); }
  void unite(long long x, long long y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    size_max = max(size[x], size_max);
    count--;
  }
  long long count_of_sets() { return count; }
  long long get_union_size(long long x) { return size[root(x)]; }
};

template <class T>
struct BIT
{
  int N;
  vector<T> bit;
  void init(int n)
  {
    N = n;
    bit.resize(n + 1, 0);
  }

  void add(int i, T x)
  {
    i++;
    while (i <= N)
    {
      bit[i] += x;
      i += i & -i;
    }
  }
  T sum(int i)
  {
    T ans = 0;
    while (i > 0)
    {
      ans += bit[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R) { return sum(R) - sum(L); }
};

template <class T>
T fsum(T a, T b)
{
  ret a + b;
}
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

  D get_node(T ind)
  {
    D rr = tree[ind += N];
    while (ind / 2 >= 1)
    {
      rr = ope(rr, tree[ind /= 2]);
    }
    ret rr;
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

// combinatorics: initFacts(m)-g zaaval duudna.
// MAXN-ee tohiruulna. m: mod. 1e9 + 7 esvel nuguu 99...
#define MAXN 100100
long long fact[MAXN], invfact[MAXN], inv[MAXN];
void initFacts(long long m)
{
  fact[0] = 1;
  invfact[0] = 1;
  inv[0] = 1;
  inv[1] = 1;

  for (int i = 1; i < MAXN; i++)
    fact[i] = (fact[i - 1] * i) % m;
  for (int i = 2; i < MAXN; i++)
    inv[i] = (-inv[m % i] * (m / i) % m + m) % m;
  for (int i = 1; i < MAXN; i++)
    invfact[i] = invfact[i - 1] * inv[i] % m;
}
long long nCk(long long n, long long k, long long m)
{
  if (k > n || k < 0)
    return 0;
  if (k == 0)
    return 1;
  return (((fact[n] * invfact[k]) % m) * invfact[n - k]) % m;
}

long long big_pow(long long a, long long b, long long mod)
{
  long long d = 1;
  while (b > 0)
  {
    if (b % 2 == 1)
      d = d * a % mod;
    b /= 2;
    a = a * a % mod;
  }
  return d;
}

// NxM matrix. 2D-vector. ex: Matrix a(2, 3);
struct Matrix
{
  vector<vector<long long>> m;
  Matrix(int row, int col) { m.resize(row, vector<long long>(col, 0)); }
};

// urjij bolhoor A, B matrix, hervee heterhii tom too bolhoor bol mod.
// ugui bol m-g arilgaad
Matrix MatrixMultification(Matrix A, Matrix B, long long m)
{
  Matrix C(A.m.size(), B.m[0].size());
  for (int i = 0; i < (int)A.m.size(); i++)
    for (int j = 0; j < (int)B.m[0].size(); j++)
      for (int k = 0; k < (int)B.m.size(); k++)
        C.m[i][j] = (C.m[i][j] + A.m[i][k] * B.m[k][j]) % m;
  return C;
}

// NxN hemjeetei matrix-iin tom zergiig big_pow-toi adilhan argaar.
Matrix matrix_pow(Matrix A, long long b, long long mod)
{
  Matrix r(A.m.size(), A.m.size());
  for (int i = 0; i < (int)A.m.size(); i++)
    r.m[i][i] = 1;
  while (b > 0)
  {
    if (b % 2 == 1)
      r = MatrixMultification(r, A, mod);
    b /= 2;
    A = MatrixMultification(A, A, mod);
  }
  return r;
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

// Longest common subsequence
// LCSSeq<vector<int>>(a, b);
// LCSSeq<string>(a, b);
template <class D>
int LCSSeq(D a, D b)
{
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      if (a[i - 1] == b[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  return n + m - 2 * dp[n][m];
}

// longest common subarray
// LCSubArr<vector<int>>(a, b);
// LCSubArr<string>(a, b);
template <class D>
int LCSubArr(D &a, D &b)
{
  int n = a.size(), m = b.size(), ans = 0;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
    {
      if (a[i] == b[j])
        dp[i][j] = dp[i + 1][j + 1] + 1;
      ans = max(ans, dp[i][j]);
    }
  return ans;
}

template <class T, class D>
struct imos2D
{
  vector<vector<T>> a;
  D h, w;
  imos2D(D hh, D ww) { h = hh, w = ww, a.assign(hh, vector<D>(ww, 0)); }

  void add(D x1, D y1, D x2, D y2, T v)
  {
    a[x1][y1] += v;
    a[x2 + 1][y2 + 1] += v;
    a[x1][y2 + 1] -= v;
    a[x2 + 1][y1] -= v;
  }
  void calc()
  {
    rep(y, w) rep(x, h - 1) a[x + 1][y] += a[x][y]; // horizontal
    rep(x, h) rep(y, w - 1) a[x][y + 1] += a[x][y]; // vertical
  }

  T node_val(D x, D y) { return a[x][y]; }

  void check()
  {
    cout << h << " " << w << '\n';
    rep(i, h)
    {
      rep(j, w) cout << a[i][j] << " ";
      cout << '\n';
    }
    cout << '\n';
  }
};

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
