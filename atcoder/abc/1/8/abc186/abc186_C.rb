n = gets.to_i
c = 0
for i in (1..n)
  next if i.to_s.include?('7') || i.to_s(8).include?('7')
  c += 1
end
puts c