# tom toonii zereg oloh. O(log(N))
# base, exp, mod damjuulna.
# hervee ymar neg toonii mod bish bol 0 damjuulah.
def power(base, exp, mod)
  if exp == 0
    return 1
  end
  if mod == 0
    if exp == 1
      return base;
    else
      return (base ** (exp % 2) * power(base, exp/2, 0) ** 2)
    end
  else
    if exp == 1
      return base % mod;
    else
      return (base ** (exp % 2) * power(base, exp/2, mod) ** 2) % mod
    end
  end
end

#C-iin n -ees k-g oloh O()
def combination(n, k, mod)
  c = 1
  d = 1
  for i in (1..k)
    c = (c * (n - k + i)) % mod
    d = (d * i) % mod
  end

  return (c * power(d, mod - 2, mod)) % mod
end

def inplist
  return gets.split.map(&:to_i)
end

n, a, b = inplist()

mod = 10 ** 9 + 7

if a != b
  X = comb(n, a, mod) + comb(n, b, mod)
else
  X = comb(n, a, mod)
end
A = power(2, n, mod) - 1 + mod
puts (A - X % mod) % mod
