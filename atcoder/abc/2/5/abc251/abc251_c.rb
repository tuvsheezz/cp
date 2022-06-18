n = gets.to_i
h = {}

n.times do |i|
  s, q = gets.chomp.split

  next if h.key?(s)

  h[s] = [q.to_i, i + 1]
end
h = h.to_a
ans = h[0][1][1]
mx = h[0][1][0]

h.each do |_, v|
  next if v[0] < mx

  ans = [ans, v[1]].min if ans == v[0]
  if mx < v[0]
    ans = v[1]
    mx = v[0]
  end
end

puts ans
