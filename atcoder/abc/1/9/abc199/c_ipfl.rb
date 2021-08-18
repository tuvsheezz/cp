n = gets.to_i
s = gets.chomp.split('')
q = gets.to_i

fl = false

q.times do
  t, a, b = gets.split.map { |x| x.to_i - 1 }
  fl = !fl if t == 1
  next if t == 1
  
  a = (a + n) % (2 * n) if fl
  b = (b + n) % (2 * n) if fl

  s[a], s[b] = s[b], s[a]
end

puts fl ? s[n..].join + s[0..n-1].join : s.join