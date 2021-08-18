s = gets.chomp

def is_lower(char)
  char >= 'a' && char <= 'z'
end

def is_upper(char)
  char >= 'A' && char <= 'Z'
end
flag = true

s.each_char.with_index do |c, i|
  if i.even? && !is_lower(c)
    flag = false
  elsif i.odd? && !is_upper(c)
    flag = false
  end
end

puts flag ? :Yes : :No
