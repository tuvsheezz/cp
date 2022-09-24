a, b, c = gets.split.map(&:to_i)

if c == 1
  puts 'No'
else
  b -= 1
  q = c
  while q <= a && b.positive?
    q *= c
    b -= 1
  end
  puts a < q ? 'Yes' : 'No'
end
