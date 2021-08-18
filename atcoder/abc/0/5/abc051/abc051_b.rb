ret = 0
k, s = gets.split.map(&:to_i)

for i in 0..k
  for j in 0..k
    ret += 1 if s - j - i <= k && s - j - i >= 0
  end
end

puts ret
