s = gets.strip
if [3].include? s[-1].to_i
  puts 'bon'
elsif [0, 1, 6, 8].include? s[-1].to_i
  puts 'pon'
else
  puts 'hon'
end
