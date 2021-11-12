s = gets.chomp.split('')
e = 0
st = 0

s << '.' if s.count('.').zero?

s.shift while s[0] == '0'
s.pop while s[-1] == '0'

di = s.index('.')

if di.zero? && s.size > 1
  e -= 1
  st = 1
  while s[st] == '0'
    st += 1
    e -= 1
  end
elsif di == s.size - 1
  s.pop
  e = s.size - 1
  s.pop while s[-1] == '0'
else
  e = di - 1
end

if s.empty?
  puts 0
else
  print(s[st])
  print '.' unless st == s.size - 1
  st += 1
  (st..s.size).each do |i|
    print s[i] unless s[i] == '.'
  end
  unless e.zero?
    print 'E'
    print e
  end
  print "\n"
end
