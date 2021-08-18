def main
  
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end
def combination(n, m)
  if m < 0 || n < m
    0
  else
    c = ((n - m + 1)..n).reduce(1, :*)
    (1..m).reduce(c, :/)
  end
end
# tom toonii zereg oloh. O(log(N))
# base, exp, mod damjuulna.
def power(base, exp, mod)
  return 1 if exp == 0
  return (base ** (exp % 2) * power(base, exp/2, mod) ** 2) % mod
end

# C-iin n -ees k-g oloh O()
def combination(n, k, mod)
  c = 1
  d = 1
  for i in (1..k)
    c = (c * (n - k + i)) % mod
    d = (d * i) % mod
  end

  return (c * power(d, mod - 2, mod)) % mod
end

main()
