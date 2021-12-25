gets.to_i.times do
  n = gets.to_i
  puts 1
  if n == 1
    puts "1 1"
  else
    puts "1 #{n * (n - 1)}"
  end
end