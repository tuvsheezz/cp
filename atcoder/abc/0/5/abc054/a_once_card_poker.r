a, b = gets.split.map(&:to_i)
a += 13 if a == 1
b += 13 if b == 1

if a == b
  puts 'Draw'
elsif a > b
  puts 'Alice'
else
  puts 'Bob'
end
  

