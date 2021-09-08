n = gets.to_i
mx = 0
s = gets.chomp.split('')
for i in (1..n-2)
  x = s[0..i].uniq & s[i + 1..-1].uniq
  mx = [mx, x.size].max
end
puts mx