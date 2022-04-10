n = gets.to_i
a = [1]

for i in 2..n
  a = a + [i] + a
  a.compact
end

puts a.join(' ')
