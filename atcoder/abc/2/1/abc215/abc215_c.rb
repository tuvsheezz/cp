s, k = gets.chomp.split
s = s.chomp.split('')
k = k.to_i
puts s.permutation.uniq.sort[k-1].join