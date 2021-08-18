def gs
  gets.chomp
end

s = gs

l, r=-1,-1
s.size.times do |i|
  l, r = i+1, i+2 if s[i]==s[i+1]
  l, r = i+1, i+3 if s[i]==s[i+2]
end

puts "#{l} #{r}"
