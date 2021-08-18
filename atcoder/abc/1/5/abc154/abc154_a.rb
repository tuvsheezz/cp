# a, b = gets.chomp.split(" ")
# c, d = gets.split.map(&:to_i)
#
# f = gets.chomp
# f == a ? c -= 1 : d -= 1
# puts "#{c} #{d}"

# puts 'x' * gets.chomp.length

n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
max = 0
for i in (k-1..n-1)
  tmp = a[i-k+1..i].inject(:+)
  if tmp > max
    max = tmp
  end
end

puts 1.0 * (k + max)/2
