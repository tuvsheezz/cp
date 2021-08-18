n = gets.to_i
m = Array.new(10).map{Array.new(10,0)}

for i in (1..n)
  m[i.to_s[0].to_i][i.to_s[-1].to_i] += 1
end
sum = 0
for i in (0..9)
  for j in (0..9)
    sum += m[i][j] * m[j][i]
  end
end
puts sum
