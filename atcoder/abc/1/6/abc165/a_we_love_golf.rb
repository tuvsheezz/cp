k = gets.to_i
a, b = gets.split.map(&:to_i)

puts (a + k - 1) / k * k <=b ? :OK : :NG