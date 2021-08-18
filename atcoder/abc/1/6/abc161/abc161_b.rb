n, m = gets.split.map(&:to_i)
v = gets.split.map(&:to_i).sort.reverse
s = 0

v.each do |vv|
  s += vv
end

c = 0

v.each do |vv|
  if vv * 4 * m >= s
    c += 1
  end
end

puts (c >= m) ? "Yes" : "No"
