n = gets.to_i
c = [1, 2, 3, 4, 5, 6, 7, 8, 9]
f = 9
if n > 9
  pre = [1, 2, 3, 4, 5, 6, 7, 8, 9]
  tmp = []
  while f < n
    tmp = []
    pre.each do |c|
      tmp << c * 10 + c%10 - 1 if c%10 != 0
      tmp << c * 10 + c%10
      tmp << c * 10 + c%10 + 1 if c%10 != 9
      f += 2 if c%10 == 0 || c%10 == 0
      f += 3 if c%10 != 0 && c%10 != 9
    end
    pre = tmp.dup
    c << pre
  end

end

puts c.flatten.uniq.sort[n-1]
