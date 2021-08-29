x, y = gets.split('.').map(&:to_i)
if y < 3
  puts "#{x}-"
elsif y < 7
  puts "#{x}"
else
  puts "#{x}+"
end