a, b = gets.split
puts [a.split('').sum(&:to_i), b.split('').sum(&:to_i)].max
