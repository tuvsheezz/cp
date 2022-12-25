def gli = gets.split.map(&:to_i)

def gi = gets.to_i

_ = gi
a = gli

c = Hash.new(0)

a.each { |x| c[x % 200] += 1 }

r = 0

c.each_value do |x|
  r += x * (x - 1) / 2
end

puts r
