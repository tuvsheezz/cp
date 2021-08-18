

# int array input
def gli
  gets.split.map(&:to_i)
end

# string array input
def gls
  gets.chomp.split
end

# integer input
def gi
  gets.to_i
end

# string input
def gs
  gets.chomp
end

# tom toonii zereg oloh. O(log(N))
# base, exp, mod damjuulna.
def power(base, exp, mod)
  return 1 if exp == 0
  return (base ** (exp % 2) * power(base, exp/2, mod) ** 2) % mod
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

MOD=10**9+7
FAC=[]
FIN=[]

def pre_process(n)
  FAC[0] = 1
  FIN[0] = power(FAC[0], MOD-2, MOD)
  for i in 1..n
    FAC[i] = FAC[i-1] * i % MOD
    FIN[i] = power(FAC[i], MOD-2, MOD)
  end
end

def combination(n, k)
  return (FAC[n] * FIN[n - k] % MOD) * FIN[k] % MOD
end
