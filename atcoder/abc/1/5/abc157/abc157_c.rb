n, m = gets.split.map(&:to_i)
k = Array.new(n, 0)
st = Array.new(n, 0)
m.times {
  s, c = gets.split.map(&:to_i)
  if st[s-1] != 0 && k[s-1] != c
    puts -1
    exit
  end
  if s == 1 and c == 0 and n > 1
    puts -1
    exit
  end
  k[s-1] = c
  st[s-1] = 1
}
if n > 1 && k[0] == 0
  k[0] = 1
end
puts k.join('')
