n, x, t = gets.split.map(&:to_i)

puts (n % x == 0 ? n / x : (n + x) / x) * t
