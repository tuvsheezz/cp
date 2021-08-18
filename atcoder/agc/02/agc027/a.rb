def main
  n, k = gli
  s = gli.sort
  ret = 0
  for i in 0..n-1
    if s[i] <= k
      k -= s[i]
      ret += 1
    end
  end

  puts ret == n && k > 0 ? ret - 1 : ret
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
