a = gets.chomp
b = gets.chomp
f = false
for x in (0..a.length)
	f = true if a[x..-1] + a[0..x-1] == b
end
puts f ? :Yes : :No
