def gl
  gets.split.map(&:to_i)
end

def gi
  gets.to_i
end

n = gi
a = gl.sort
s = 0

for i in (0..2*n-1)
  s += a[i] if i.even?
end
puts s
