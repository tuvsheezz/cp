def is_pal(s)
  return s == s.reverse
end

s = gets.chomp

s1 = s[0..(s.size-1)/2-1]
s2 = s[(s.size+3)/2-1..s.size-1]

puts (is_pal(s) && is_pal(s1) && is_pal(s2) && s.size%2==1) ? "Yes" : "No"
