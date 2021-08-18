t = gets.to_i
x = 0
while t > 0
  x += t%10
  t /= 10
end

puts x == 1 ? 10 : x
