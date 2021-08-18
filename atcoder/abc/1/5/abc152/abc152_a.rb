def gli
  gets.split.map(&:to_i)
end

a, b = gli
puts (a == b) ? :Yes : :No
