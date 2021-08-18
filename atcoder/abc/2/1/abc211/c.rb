MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end
def narr0(n); Array.new(n, 0); end

def main
  s = gs
  dp = narr0(8)
  s.each_char do |c|
    dp[0] += 1 if c == 'c'
    dp[1] = (dp[1] + dp[0]) % MOD if c == 'h'
    dp[2] = (dp[2] + dp[1]) % MOD if c == 'o'
    dp[3] = (dp[3] + dp[2]) % MOD if c == 'k'
    dp[4] = (dp[4] + dp[3]) % MOD if c == 'u'
    dp[5] = (dp[5] + dp[4]) % MOD if c == 'd'
    dp[6] = (dp[6] + dp[5]) % MOD if c == 'a'
    dp[7] = (dp[7] + dp[6]) % MOD if c == 'i'
  end

  puts dp[7]
end

main
