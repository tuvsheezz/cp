#include <bits/stdc++.h>
using namespace std;
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;

struct Graph
{
  int vertices;
  vector<vector<pair<int, int>>> edges;

  Graph(int n){
    vertices = n;
    edges.resize(n);
  }

  void add_edge(int u, int v, int w) {
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  void Prim() {
    
  }

};


int main()
{

  return 0;
}
