a, b, c = gets.split.map(&:to_i)
if c == 0
  puts a > b ? :Takahashi : :Aoki
else
  puts a < b ? :Aoki : :Takahashi
end