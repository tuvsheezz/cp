n = gets.to_i
r = 0
1.upto(n) { |i| r += n % i == 0 ? n / i - 1 : n / i }
puts r
