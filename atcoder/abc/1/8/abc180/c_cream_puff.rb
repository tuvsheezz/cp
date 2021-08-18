n = gets.to_i
r = []
1.upto((n**0.5).to_i) do |i|
  r += [n / i, i] if (n % i).zero?
end

puts r.uniq.sort
