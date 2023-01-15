#define pll pair<long long, long long>
class Solution {
public:
    struct Graph
    {
        int V;
        vector<set<int>> E;
        vector<pll> a, b;
        long long ans = 0;
        
        Graph(int n, vector<int> &p)
        {
            V = n;
            E.resize(n);
            a.resize(n);
            b.resize(n);
            for(int i = 0; i < n; i++) {
                a[i] = { p[i], p[i] };
                b[i] = { p[i], p[i] };
            }
        }

        void add_edge(int u, int v)
        {
            E[u].insert(v);
            E[v].insert(u);
        }
        
        void Fun()
        {
            queue<int> next;
            for(int i = 0; i < V; i++) {
                if(E[i].size() == 1) next.push(i);
            }
            while(!next.empty()) {
                int cur = next.front();
                next.pop();
                
                auto q = *(E[cur].begin());
                
                E[q].erase(cur);
                E[cur].erase(q);

                if(E[q].size() == 1) next.push(q);
                
                int xx = b[q].first + b[cur].first;
                ans = max(ans, xx - b[q].second);
                ans = max(ans, xx - b[cur].second);
                
                if(b[cur].first - b[cur].second > b[q].first - b[q].second) {
                    b[q] = { b[cur].first + a[q].first, b[cur].second };
                }
            }
          }
    };
    
    long long maxOutput(int n, vector<vector<int>>& e, vector<int>& price) {
        Graph G(n, price);
        for(int i = 0; i < n - 1; i++)
            G.add_edge(e[i][0], e[i][1]);
        G.Fun();
        return G.ans;
    }
};