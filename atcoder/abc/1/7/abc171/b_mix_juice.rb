n, k = gets.split.map(&:to_i)
l = gets.split.map(&:to_i).sort
puts l[0..k-1].sum
