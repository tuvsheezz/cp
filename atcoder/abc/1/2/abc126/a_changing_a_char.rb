_, b = gets.split.map(&:to_i)
s = gets.split('')
s[b-1] = s[b-1].downcase
puts s.join
