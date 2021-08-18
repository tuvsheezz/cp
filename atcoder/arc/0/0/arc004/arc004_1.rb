n = gets.to_i
co = []
n.times {
  co << gets.split.map(&:to_i)
}
mx = 0
for i in 0..n-1
  for j in i+1..n-1
    d = ((co[i][0] - co[j][0]) ** 2 + (co[i][1] - co[j][1]) ** 2).to_f ** 0.5
    mx = d if mx < d
  end
end
puts mx
