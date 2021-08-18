s = gets.strip.split('')
t = gets.strip.split('')

n = s.size
m = t.size
ans = n

n.times do |i|
  break if i + m > n

  c = 0
  m.times do |j|
    c += 1 if s[i + j] != t[j]
  end
  ans = c if ans > c
end

p ans
