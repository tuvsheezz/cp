x, y, a, b = gets.split.map(&:to_i)
ans = 0
while x * (a - 1) < b && x * a < y
  ans+=1
  x *= a
end

ans += (y - x) / b
ans -= 1 if((y - x) % b == 0)

puts ans