n, d, h = gets.split.map(&:to_i)

res = 0

n.times do
  x, y = gets.split.map(&:to_f)
  t = (d * y - x * h)/(d - x)
  res = t if t > res
end

puts res