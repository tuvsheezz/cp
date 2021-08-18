k, q = gets.split.map(&:to_i)
d = gets.split.map(&:to_i)

q.times {
  n, x, m = gets.split.map(&:to_i)
  a = []
  if j == 0
    a[j] == x
  else
    a[j] = a[j-1] + d[(j-1) % k]
  end

  if a[j] % m < a[j + 1] % m
    count += 1
  end
}
