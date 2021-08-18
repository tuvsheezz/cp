def gs
  gets.chomp
end

S = gs
r = 0
S.split(//).each { |x|
  r ^= x.ord
}

puts r == 0 ? :Yes : :No
