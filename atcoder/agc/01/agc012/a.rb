a, b = gets.chomp.split(":")
a = a.split("")
x = a[0]
x1 = a[1..].join.to_a

b = b.split("")
y = b[0]
y1 = b[1..].join.to_a

puts x
puts x1
puts y
puts y1