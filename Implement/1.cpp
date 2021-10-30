
ll Dijkstra(vector<vector<pair<int, int>>> &matrix, ll start, ll finish)
{
  int n = matrix.size();
  vector<int> lengths(n, INF), p(n);
  lengths[start] = 0;
  set<pair<int, int>> mas;
  mas.insert(make_pair(lengths[start], start));
  while (!mas.empty())
  {
    int v = mas.begin()->second, len = mas.begin()->first;
    mas.erase(mas.begin());
    if (len > lengths[v])
      continue;
    forin(0, matrix[v].size())
    {
      int n_v = matrix[v][i].first, n_len = len;
      char llen = len % 7;
      if (llen > matrix[v][i].second)
        n_len += matrix[v][i].second + 7 - llen + 1;
      else
        n_len += matrix[v][i].second - llen + 1;
      if (lengths[n_v] > n_len)
      {
        mas.erase(make_pair(lengths[n_v], n_v));
        lengths[n_v] = n_len;
        mas.insert(make_pair(n_len, n_v));
      }
    }
  }
  return lengths[finish];
};
