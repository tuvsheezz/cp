a, b = gets.split.map(&:to_i)
lcm = a.lcm(b);
puts (lcm > 10 ** 18) ? :Large : lcm
