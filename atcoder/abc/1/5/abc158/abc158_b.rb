def gli
  gets.split.map(&:to_i)
end

n, a, b = gli

c = n / ( a + b ) * a

if a <= n % (a + b)
  c += a
else
  c += n % (a + b)
end

puts c
