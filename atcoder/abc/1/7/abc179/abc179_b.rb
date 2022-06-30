s = ''
n = gets.to_i
n.times do
  a, b = gets.split.map(&:to_i)
  s += a == b ? '1' : '0'
end

puts s.include?('111') ? 'Yes' : 'No'
