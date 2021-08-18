n = gets.to_i
s = gets.chomp.split("").map(&:to_i)

ret = 0
puts s.to_s
for i in (0..n-1)
  for j in (0..n-2-i)
    s[j] = (s[j]-s[j+1]).abs
  end
  puts s[0..n-2-i].to_s
end

puts s[0]
