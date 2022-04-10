a, b, c, d = gets.split.map(&:to_i)

tak = Time.new(2022, 3, 26, a, b, 0)
aok = Time.new(2022, 3, 26, c, d, 1)

if tak < aok
  puts 'Takahashi'
else
  puts 'Aoki'
end
