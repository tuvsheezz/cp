a = gets.strip
if (a[0] == a[1] && a[1] == a[2]) || (a[3] == a[1] && a[1] == a[2])
  puts 'Yes'
else
  puts 'No'
end
