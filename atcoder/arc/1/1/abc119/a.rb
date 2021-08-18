n = gets.to_i
res = n
ex = 0

while 2 ** ex < n do
  ex += 1
  f = n / (2 ** ex)
  g = n - f * (2 ** ex)
  c = f + g + ex
  res = c if c < res
end

puts res