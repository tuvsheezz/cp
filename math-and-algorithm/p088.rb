a, b, c = gets.split.map(&:to_i)
aa = ((a + 1) * a * (b + 1) * b * c * (c + 1) / 8) % 998_244_353
puts aa
