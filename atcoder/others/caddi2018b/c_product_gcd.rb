require 'prime'
n, x = gets.split.map(&:to_i)

a = Prime.prime_division(x)
r = 1
a.each do |x, y|
  r = r * x ** (y / n)
end
puts r