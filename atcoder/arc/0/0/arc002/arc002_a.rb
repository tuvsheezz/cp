n = gets.to_i
if (n % 400).zero? || ((n % 4).zero? && n % 100 != 0)
  puts 'YES'
else
  puts 'NO'
end
