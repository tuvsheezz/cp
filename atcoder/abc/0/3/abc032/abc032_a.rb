a = gets.to_i
b = gets.to_i
n = gets.to_i

# while n%a != 0 || n%b != 0
#   n += 1
# end
# puts n

def gcd(a, b)
  if b == 0
    return a
  else
    return gcd(b, a%b)
  end
end

def lcm (a, b)
  return a * b / gcd(a, b)
end

c = lcm(a, b)

puts (n + c -1)/c * c
