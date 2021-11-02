n = gets.to_i * 2
c = []
i = 1
while i * i <= n
  if (n % i).zero?
    c << i
    c << n / i if n / i != i
  end
  i += 1
end
ans = 0
c.each { |x| ans += 1 if (n / x - x + 1).even? }
puts ans
