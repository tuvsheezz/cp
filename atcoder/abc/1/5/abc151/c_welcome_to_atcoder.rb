def gs; gets.chomp; end
def gli; gets.split.map(&:to_i); end

ac = {}
wa = {}
aa = 0
ww = 0
_n, m = gli

m.times do
  pr, r  = gets.split(' ')
  pr = pr.to_i
  next if ac[pr]
  if r == 'AC'
    ac[pr] = 1
  else
    wa[pr] = wa[pr].to_i + 1
  end
end

ac.each do |k, v|
  aa += 1
  ww += wa[k].to_i
end

puts "#{aa} #{ww}"
