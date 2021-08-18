def gs
  gets.chomp.split('')
end

def checkee(x, s)
  s.each_with_index do |d, i|
    if d == 'o'
      return false unless x.include?(i.to_s)
    elsif d == 'x'
      return false if x.include?(i.to_s)
    end
  end
  true
end
s = gs


e = []

for i1 in 0..9 do
  for i2 in 0..9 do
    for i3 in 0..9 do
      for i4 in 0..9 do
        e << i1.to_s + i2.to_s + i3.to_s + i4.to_s
      end
    end
  end
end

e = e.map { |x| x if checkee(x, s) }.compact

puts e.size