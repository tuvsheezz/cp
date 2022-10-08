n = gets.to_i.to_s(16).upcase
if n.size == 1
  puts '0' + n
else
  puts n
end
