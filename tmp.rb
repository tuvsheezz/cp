a, b = gets.split.map(&:to_i)
s = a.to_s(2)
t = b.to_s(2)
f = 0
if s == t
  f += 1
end

if t.index(s) && s[-1] == '1'
  ff = true
  t.sub(s, '').each_char { |c| ff = false unless c == '1' }
  f += 1 if ff
end

s = s.reverse
while s[0] == '0' do  
  s[0] = ''
end

if t.index(s)
  ff = true
  t.sub(s, '').each_char { |c| ff = false unless c == '1' }
  f += 1 if ff
end

if t.index(s.reverse)
  ff = true
  t.sub(s.reverse, '').each_char { |c| ff = false unless c == '1' }
  f += 1 if ff
end

puts f.positive? ? :YES : :NO
