_, x = gets.split.map(&:to_i)
c = gets.split.map(&:to_i)
dp = Array.new(x + 1, 0)
dp[0] = 1

c.each_with_index do |cc, _j|
  (0..x).each do |i|
    dp[i] = (dp[i] + dp[i - cc]) % 1_000_000_007 if i >= cc
  end
end

puts dp[x]
