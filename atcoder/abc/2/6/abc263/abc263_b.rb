n = gets.to_i
a = gets.split.map(&:to_i)
ans = 1
c = n
while a[c - 2] != 1
  c = a[c - 2]
  ans += 1
end
puts ans
