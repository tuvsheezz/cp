_ = gets
a = gets.split.map(&:to_i)

puts a.map(&:abs).sum
puts a.map { |i| i**2 }.sum**0.5
puts a.map(&:abs).max
