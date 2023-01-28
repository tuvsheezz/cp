#include <bits/stdc++.h>
using namespace std;

template <int char_size, int base>
struct Trie
{
  struct Node
  {                     
    vector<int> next;
    int c;
    int common;
    Node(int c_) : c(c_), common(0)
    {
      next.assign(char_size, -1);
    }
  };
  vector<Node> nodes;
  int root;
  Trie() : root(0)
  {
    nodes.push_back(Node(root));
  }
  // 単語の挿入
  void insert(const string &word, int word_id)
  {
    int node_id = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
      int c = (int)(word[i] - base);
      int &next_id = nodes[node_id].next[c];
      if (next_id == -1)
      {
        next_id = (int)nodes.size();
        nodes.push_back(Node(c));
      }
      ++nodes[node_id].common;
      node_id = next_id;
    }
    ++nodes[node_id].common;
  }
  void insert(const string &word)
  {
    insert(word, nodes[0].common);
  }
  int search(const string &word)
  {
    int node_id = 0, ret = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
      int c = (int)(word[i] - base);
      int &next_id = nodes[node_id].next[c];
      if (next_id == -1)
      {
        return ret;
      }
      if(nodes[node_id].common > 1 && node_id > 0) { ret++; }
      node_id = next_id;
    }
    if(nodes[node_id].common > 1 && node_id > 0) { ret++; }
    return ret;
  }
};
int main()
{
  Trie<26, 'a'> trie;
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for(int i = 0; i < n; i++) {
    trie.insert(s[i]);
  }
  for(int i = 0; i < n; i++) {
    cout << trie.search(s[i]) << endl;
  }
  return 0;
}
