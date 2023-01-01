v, s, t, d = gets.split.map(&:to_i)

puts (v * s > d || v * t < d) ? :Yes : :No