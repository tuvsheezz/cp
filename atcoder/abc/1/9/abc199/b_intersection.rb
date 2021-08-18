gets
a = gets.split.map(&:to_i).max
b = gets.split.map(&:to_i).min
puts [b - a + 1, 0].max