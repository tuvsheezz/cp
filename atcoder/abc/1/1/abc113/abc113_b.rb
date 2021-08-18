n = gets.to_i
t, a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)

for i in 0..n-1
    b[i] = (t * 1000 - b[i] * 6 - 1000 * a).abs
end

puts b.index(b.min) + 1
