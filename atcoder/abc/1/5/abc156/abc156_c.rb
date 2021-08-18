gets
r = gets.split.map(&:to_i)
min = r.reduce(0) { |q, x| q + x ** 2 }

for i in r.min..r.max
  c = r.reduce(0) { |q, x| q + (x - i) ** 2 }
  min = c if c < min
end

puts min
