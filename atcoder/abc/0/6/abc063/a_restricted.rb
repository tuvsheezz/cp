a, b = gets.split.map(&:to_i)
puts a + b < 10 ? a + b : :error
