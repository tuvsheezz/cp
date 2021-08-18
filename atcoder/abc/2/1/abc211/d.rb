MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def bfs(adj, src, dist, paths, n)
  visited = Array.new(n, false)
  dist[src] = 0
  paths[src] = 1
  q = Array.new(1, src)

  visited[src] = true

  while q.any? do
    curr = q[0]
    q.shift

    # For all neighbors of current vertex do:
    adj[curr].each do |x|
      # if the current vertex is not yet
      # visited, then push it to the queue.
      unless visited[x]
        q.push(x)
        visited[x] = true
      end
      
      # check if there is a better path. 
      if dist[x] > dist[curr] + 1
        dist[x] = dist[curr] + 1
        paths[x] = paths[curr]
      # additional shortest paths found
      elsif dist[x] == dist[curr] + 1
        paths[x] += paths[curr]
      end
    end
  end
end

def find_shortest_paths(adj, s, n)
  dist = Array.new(n, Float::INFINITY)
  paths = Array.new(n, 0)
  bfs(adj, s, dist, paths, n)
  return paths
end
 
def add_edge(adj, u, v)
  adj[u].push(v)
  adj[v].push(u)
end

def main
  n, m = gli
  adj = []
  for i in (0..n - 1)
    adj[i] = []
  end
  m.times do
    u, v = gli
    add_edge(adj, u - 1, v - 1)
  end
  puts find_shortest_paths(adj, 0, n)[-1] % MOD
end

main