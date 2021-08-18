def gi
  gets.to_i
end
N = gi
K = gi
X = gi
Y = gi

if N <= K
  puts X * N
else
  puts X * K + Y * (N-K)
end
