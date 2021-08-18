n, h, w = gets.split.map(&:to_i)
c = 0
n.times do
  a, b = gets.split.map(&:to_i)
  c += 1 if h <= a && w <= b
end
puts c