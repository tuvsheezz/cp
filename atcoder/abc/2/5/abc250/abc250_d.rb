maxn = 1_001_001
n = gets.to_i
f = Array.new(maxn) { 0 }
primes = []
f[0] = -1
f[1] = -1

(2...maxn).each do |i|
  next if f[i].positive?

  primes << i
  f[i] = i
  (i * i).step(by: i, to: maxn - 1) do |j|
    break unless f[j]

    f[j] = i if f[j].zero?
  end
end

ans = 0
nn = primes.size
(0...nn).each do |i|
  break if primes[i] > n

  (i + 1...nn).each do |j|
    break if primes[i] * primes[j] * primes[j] * primes[j] > n

    ans += 1
  end
end
puts ans
