n, m = gets.split.map(&:to_i)
a = n.times.map{ gets.chomp }
b = m.times.map{ gets.chomp }
 
puts n.times.find{ |y| n.times.find{ |x| a[y, m].map{|a| a[x, m] } == b} } ? :Yes : :No