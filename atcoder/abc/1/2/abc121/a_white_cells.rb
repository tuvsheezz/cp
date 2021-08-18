h, w = gets.split.map(&:to_i)
hp, wp = gets.split.map(&:to_i)

puts (h - hp) * (w - wp)