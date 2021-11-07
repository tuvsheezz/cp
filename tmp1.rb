n, k = gets.split.map(&:to_i)

if k.odd?
  puts (n / k)**3
else
  puts (n / k)**3 + ((n + k / 2) / k)**3
end
