n = gets.to_i
r = 0
n.times do
  a, b = gets.split.map(&:to_i)
  r += (b + a) * (b - a + 1) / 2
end
puts r
