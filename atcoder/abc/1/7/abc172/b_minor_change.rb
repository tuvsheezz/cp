s = gets.chomp.split('')
t = gets.chomp.split('')

puts s.select.with_index { |x, i| x != t[i] }.size