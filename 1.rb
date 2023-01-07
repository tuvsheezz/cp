max_n = 3_000_000
f = Array.new(max_n, 0)
f[0] = -1
f[1] = -1

(2...max_n).each do |i|
  next if f[i].positive?

  f[i] = i
  (i * i...max_n).each do |j|
    f[j] = i if (j % i).zero?
  end
end

# gets.to_i.times do
#   n = gets.to_i
#   puts f[n]
# end
