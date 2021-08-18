def gli
  gets.split.map(&:to_i)
end
n, a = gli
x = gli
for i in 0..x.size-1
  x[i] -= a
end

dp = {}
dp[0] = 1
n.times { |i|
  tmp = dp.dup
  dp.each { |k, v|
    if tmp.has_key? (x[i] + k)
      tmp[x[i] + k] += v
    else
      tmp[x[i] + k] = v
    end
  }
  dp = tmp.dup
}

puts dp[0] - 1
