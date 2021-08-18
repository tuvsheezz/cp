def main
  n, k = gli
  c = gli
  x = array_to_hash_by_count(c[0..k-1])
  max = x.size
  q = max

  for i in k..n-1
    x[c[i - k]] -= 1

    q -= 1 if x[c[i - k]] == 0

    if x[c[i]] == 0
      x[c[i]] = 1
      q += 1
    else
      x[c[i]] += 1
    end
    
    max = q if q > max
  end

  puts max
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
