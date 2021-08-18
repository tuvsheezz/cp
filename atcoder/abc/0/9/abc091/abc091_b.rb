c = {}
n = gets.to_i
n.times {
  d = gets.chomp
  if c.has_key?(d)
    c[d] += 1
  else
    c[d] = 1
  end
}
n = gets.to_i
n.times {
  d = gets.chomp
  if c.has_key?(d)
    c[d] -= 1
  else
    c[d] = -1
  end
}


puts (c.values + [0]).max
