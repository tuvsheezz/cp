def gi
 gets.to_i
end

def gli
  gets.split.map(&:to_i)
end

n = gi
dt = (1..n).to_a.permutation.to_a

p = dt.index(gli)
q = dt.index(gli)

puts (p-q).abs