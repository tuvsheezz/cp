n, s = gets.split.map(&:to_i)
c = gets.split.map(&:to_i)

def isSubsetSum(ret, set, n, sum, l, r)
  if sum == 0
    ret = (ret + (l + 1) * (n - r + 1)) % 998244353
  end
  if n == 0 && sum != 0
    return 0
  end
  return isSubsetSum(ret, set, n, sum, l, r-1) if set[r-1] > sum
  return isSubsetSum(ret, set, n, sum, l, r-1) || isSubsetSum(ret, set, r-1, sum-set[r-1], l, r-1)
end

if (isSubsetSum(0, c, n, s, 0, n-1) == true)
	puts "Found a subset with given sum"
else
	puts "No subset with given sum"
end

puts isSubsetSum(0, c, n, s, 0, n-1)
