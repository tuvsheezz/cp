# nCk
def combination(n, k)
  return 0 if n < k
  return 0 if k == 0
  ret = 1
  for i in (1..k)
    ret = ret * (n - i + 1) / i 
  end
  ret
end

L = gets.to_i
puts combination(L-1, 11)

