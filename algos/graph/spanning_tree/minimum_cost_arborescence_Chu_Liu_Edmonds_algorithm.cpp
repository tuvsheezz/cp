/*
有向木の最小全域木を求める.
O(|V|*|E|^2)らしい.知らんけど
*/
template <class T>
T Chu_Liu_Edmonds_algorithm(const vector<pair<T, paii>> &E, int v, int root = 0)
{ // E:{重み,{start,end}} //v:|V| //root:根

  vector<pair<T, int>> Vm(v, pair<T, int>(1e9, -1));
  vector<int> gr(v, 0);
  vector<bool> P(v, false), f(v, false);
  int cnt = 0;
  T res = 0;
  vector<pair<T, paii>> nE;

  for (auto e : E)
  {
    chmin(Vm[e.ss], {e.first, e.sf});
  }
  Vm[root] = paii(-1, -1);

  rep(i, v)
  {
    if (f[i])
      continue;
    vector<int> ch;
    int x = i;
    while (x != -1 && !f[x])
    {
      f[x] = 1;
      ch.push_back(x);
      x = Vm[x].second;
    }
    if (x == -1)
    {
      rep(j, ch.size())
      {
        gr[ch[j]] = cnt;
        cnt++;
      }
    }
    else
    {
      bool Q = 0;
      for (long long j : ch)
      {
        gr[j] = cnt;
        if (j == x)
        {
          P[cnt] = 1;
          Q = 1;
        }
        if (!Q)
          cnt++;
      }
      if (Q)
        cnt++;
    }
  }
  if (cnt == v)
  {
    res = 1;
    rep(i, v) res += Vm[i].first;
    return res;
  }

  rep(i, v)
  {
    if (i != root && P[gr[i]])
      res += Vm[i].first;
  }

  for (auto e : E)
  {
    int p = e.ss;
    int s = gr[e.sf];
    int t = gr[e.ss];
    if (s == t)
      continue;
    else if (P[t])
    {
      nE.emplace_back(e.first - Vm[p].first, paii(s, t));
    }
    else
    {
      nE.emplace_back(e.first, paii(s, t));
    }
  }

  return res + Chu_Liu_Edmonds_algorithm(nE, cnt, gr[root]);
}
