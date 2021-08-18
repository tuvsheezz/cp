from collections import deque
from sys import maxsize as INT_MAX
 
def BFS(adj: list, src: int, dist: list, paths: list, n: int):
    visited = [False] * n
    dist[src] = 0
    paths[src] = 1
 
    q = deque()
    q.append(src)
    visited[src] = True
    while q:
        curr = q[0]
        q.popleft()
 
        for x in adj[curr]:
            if not visited[x]:
                q.append(x)
                visited[x] = True
 
            if dist[x] > dist[curr] + 1:
                dist[x] = dist[curr] + 1
                paths[x] = paths[curr]
 
            elif dist[x] == dist[curr] + 1:
                paths[x] += paths[curr]
 
def findShortestPaths(adj: list, s: int, n: int):
    dist = [INT_MAX] * n
    paths = [0] * n
    BFS(adj, s, dist, paths, n)
    print(paths[-1] % 1000000007)
 
def addEdge(adj: list, u: int, v: int):
    adj[u].append(v)
    adj[v].append(u)
 
if __name__ == "__main__":
    n, m = map(int, input().split())
    adj = [0] * n
    for i in range(n):
        adj[i] = []
    for i in range(m):
        x, y = map(int, input().split())
        addEdge(adj, x - 1, y - 1)
    findShortestPaths(adj, 0, n)
 
