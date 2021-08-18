s = gets.chomp
d = s.chars.map.with_index { |x, i| x if i.even? }
puts d.join
