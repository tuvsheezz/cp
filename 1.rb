t = [2, 1, 2, 4, 2, 2]
b = [5, 2, 6, 2, 3, 2]

a = 0
b = 0
n = t.size

(0...n).each do |i|
  break if (t[i] != t[0]) && (b[i] != t[0])

  a += 1 if t[i] != t[0]
  b += 1 if b[i] != t[0]

  puts [a, b].min if i == n - 1
end
c = 0
d = 0
(0...n).each do |i|
  break if (t[i] != b[0]) && (b[i] != b[0])

  c += 1 if t[i] != b[0]
  d += 1 if b[i] != b[0]

  puts [c, d].min if i == n - 1
end
puts(-1)
