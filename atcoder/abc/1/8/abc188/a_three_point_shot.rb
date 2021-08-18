a, b = gets.split.map(&:to_i)
puts (a - b).abs < 3 ? 'Yes' : 'No'
