a = gets.strip
if a.include? 'RRR'
  puts 3
elsif a.include? 'RR'
  puts 2
elsif a.include? 'R'
  puts 1
else
  puts 0
end
