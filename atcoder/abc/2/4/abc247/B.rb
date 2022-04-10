n = gets.to_i

a = []
b = []
c = []
n.times do
  x, y = gets.chomp.split
  a.push x
  b.push y
  c.push x
  c.push y unless x == y
end
f = true
(0...n).each do |i|
  cc = c.count(a[i])
  dd = c.count(b[i])
  f = false unless cc == 1 || dd == 1
end
puts f ? :Yes : :No
