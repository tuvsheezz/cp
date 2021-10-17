a = gets.chomp
q = []
(a.size + 1).times do
  q << a
  a = a[-1] + a[0..-2]
end

q.sort!

puts q[0]
puts q[-1]
