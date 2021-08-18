n = gets.to_i
s = gets.split.map(&:to_i).sort.reverse
ret = 0
for i in 0..n-1
  ret += s[i * 2 + 1]
end

puts ret
