def gli
  gets.split.map(&:to_i)
end

n, k = gli

k.times do
  if (n % 200).zero?
    n /= 200
  else
    n = n * 1000 + 200
  end
end

puts n
