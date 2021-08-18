m = 10**9 + 7
gets
s = gets.split.map(&:to_i)
ss = s.sum % m

r = 0
s.each do |v|
  ss = ss + m - v
  r += (v * ss) % m
end

puts r % m
