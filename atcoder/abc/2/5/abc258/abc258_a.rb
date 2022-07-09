n = gets.to_i
a = n % 60
b = 21 + n / 60
if a >= 10
  puts "#{b}:#{a}"
else
  puts "#{b}:0#{a}"
end
