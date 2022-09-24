a, b = gets.split.map(&:to_i)
c = a.lcm(b)
if c > 1e18
  puts 'Large'
else
  puts c
end
