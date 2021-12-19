n, k = gets.split.map(&:to_i)
while k > 0
  tmp = n.to_i
  b10 = 0
  p = 1
  b9 = 0
  q = 1
  while tmp > 0
    b10 += p * (tmp % 10);
    tmp /= 10;
    p *= 8;
  end

  while b10 > 0
    d = (b10 % 9 == 8) ? 5 : b10 % 9;
    b9 += d * q;
    b10 /= 9;
    q *= 10;
  end
  n = b9;
  k -= 1
end
puts n