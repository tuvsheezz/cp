n, s, d = gets.split.map(&:to_i)
flag = false
n.times do
  x, y = gets.split.map(&:to_i)
  flag = true if x < s && y > d
end

puts flag ? :Yes : :No