n = gets.to_i
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
c = 0
1.upto(n) do |i|
  c += a[i-1] * b[i-1]
end
puts c == 0 ? :Yes : :No
