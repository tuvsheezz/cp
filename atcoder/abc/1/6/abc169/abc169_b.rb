n = gets.to_i
ans = 0
a = gets.split.map(&:to_i).sort
ans = a[0]
for i in (1..n-1)
  ans *= a[i]
  if(ans > 10 ** 18)
    ans = -1
    break
  end
end
puts ans