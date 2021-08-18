n, k = gets.split.map(&:to_i)

puts [n % k, (k-n%k).abs].min
