MOD=10**9+7
FAC=[]
FIN=[]

def gli
  return gets.split.map(&:to_i)
end

def power(base, exp, mod)
  return 1 if exp == 0
  return (base ** (exp % 2) * power(base, exp/2, mod) ** 2) % mod
end

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

H, W, A, B = gli

pre_process(H + W)

ret = 0

for i in 1..H-A do
  ret += combination(i + B - 2, B - 1) * combination(H + W - i - B - 1, W - B - 1) % MOD
end

puts ret % MOD
