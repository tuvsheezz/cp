_ = gets.to_i
d = gets.split.map(&:to_i)

mx = 0
ret = nil

2.upto 1000 do |i|
  tmp = 0
  d.each do |dd|
    tmp += 1 if dd%i == 0
  end
  if tmp > mx
    ret = i
    mx = tmp
  end
end

puts ret
