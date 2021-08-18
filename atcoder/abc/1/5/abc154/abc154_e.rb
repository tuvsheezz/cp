s = gets.chomp.split("").map(&:to_i)
k = gets.to_i

puts s.to_s

sum = 0

for i in (0..s.size-1-k)
  d = 1
  for j in (0..k)
    d *= (s.size - i - 1 - j)
  end

  for j in (1..k+1)
    d /= j
  end

  sum +=(s[i] - 1) * d

end

puts sum
