class Graph
  def initialize(n, dir = false)
    @edges = Array.new(n) { Array.new(0) }
    @is_directed = dir
  end

  def add_edge(u, v)
    @edges[u] << v
    @edges[v] << u unless @is_directed
  end

  def check_graph
    @edges.each { |x| puts x.to_s }
  end
end

def diameter_of_binary_tree
  n = gets.to_i
  m = gets.to_i
  g = Graph.new(n, true)

  m.times do
    u, v = gets.split.map(&:to_i)
    g.add_edge(u - 1, v - 1)
  end

  g.check_graph
end

diameter_of_binary_tree
