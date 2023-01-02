n = gets.to_i
a = gets.split.map(&:to_i)
dp = Array.new(n + 1) { Array.new(21, 0) }
dp[0][0] = 1
n.times do |i|
  21.times do |j|
    dp[i + 1][j] += dp[i][j - a[i]] if j - a[i] >= 0
    dp[i + 1][j] += dp[i][j + a[i]] if j + a[i] <= 20
  end
end
puts dp[n][0]
