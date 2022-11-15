x = %w[H D C S]
y = %w[A 2 3 4 5 6 7 8 9 T J Q K]
f = true
n = gets.to_i
a = []
n.times { a << gets.chomp }
a.each do |c|
  f = false unless x.include?(c[0]) and y.include?(c[1])
end
if f && a.uniq.size == a.size
  puts 'Yes'
else
  puts 'No'
end
