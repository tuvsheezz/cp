n = gets.to_i
pow  = 0
while 2 ** (pow + 1) <= n
  pow += 1
end
puts 2 ** pow
