n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

w = a[0..k-1].inject(:+)
prev = w

for i in (k..n-1)
  prev = prev + a[i] - a[i-k]
  w = [w, prev].max
end

puts 1.0 * (k + w)/2
