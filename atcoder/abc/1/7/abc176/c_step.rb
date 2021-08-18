gets
a = gets.split.map(&:to_i)
r = 0
1.upto(a.size - 1) do |i|
  r += [a[i - 1] - a[i], 0].max
  a[i] = [a[i], a[i - 1]].max
end

puts r
