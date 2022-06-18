a, b = gets.split.map(&:to_i)
g = []
2.times { g << gets.split.map(&:to_i) }
puts g[a - 1][b - 1]
