def gli
  gets.split.map(&:to_i)
end

n, k, m = gli
a = gli.sum

puts n * m - a <= k ? [n * m - a, 0].max : -1
