s = gets.chomp
puts s.split('').uniq.size == 1 ? 'Won' : 'Lost'
