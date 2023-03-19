a = gets.split.map(&:to_i).tally.to_a

if a.size == 2 && a[0][1] == 2 && a[1][1] == 3
  puts "Yes"
elsif a.size == 2 && a[0][1] == 3 && a[1][1] == 2
  puts "Yes"
else
  puts "No"
end
