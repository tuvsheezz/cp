def gl
  gets.split.map(&:to_i)
end

def trapets(h, g)
  if g > h
    trapets(g, h)
  end
  if h == g
    return g
  elsif h % g == 0
    return 2 * h - g
  else
    return 2 * g *(h/g) + trapets(g,h%g)
  end
end

n, x = gl

puts n + trapets(n-x, x)
