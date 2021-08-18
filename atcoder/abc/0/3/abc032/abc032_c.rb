n, k = gets.split.map(&:to_i)
s = []
for i in 1..n
  s << gets.to_i
end

m = 1
r = 0
ri = 0

for left in 0..n-1
  if s[left] == 0
    puts n
    exit
  end

  while ri < n && m * s[ri] <= k
    m *= s[ri]
    ri += 1
  end
  r = [r, ri - left].max
  if left == ri
    ri += 1
  else
    m /= s[left]
  end
end

puts r
