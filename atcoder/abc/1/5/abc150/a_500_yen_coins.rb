def gli
  gets.split.map(&:to_i)
end

A, N = gli
puts (A * 500 >= N) ? :Yes : :No
