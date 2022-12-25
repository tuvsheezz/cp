def is_valid(s)
  return false if s.length != 8
  return false unless s[0].match?(/[A-Z]/) && s[7].match?(/[A-Z]/)
  return false unless s[1..6].match?(/\d{6}/) && s[1].match?(/[1-9]/)
  return true
end
 
puts is_valid(gets.chomp) ? "Yes" : "No"