# frozen_string_literal: true

a, b = gets.split.map(&:to_i)
c, d = gets.split.map(&:to_i)
p = (a - c).abs
q = (b - d).abs
if p.zero? && q.zero?
  puts 0
elsif p == q || p + q <= 3
  puts 1
elsif (p + q).even? || (p + q) <= 6 || (p - q).abs <= 3
  puts 2
else
  puts 3
end
