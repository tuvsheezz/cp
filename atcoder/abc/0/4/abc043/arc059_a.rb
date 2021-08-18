FIXMAX = 2**62 - 1
FIXMIN = -2**62
def gli
  gets.split.map(&:to_i)
end

n = gets.to_i
c = gli
mn =  FIXMAX
for i in (c.min..c.max)
  tmp = 0
  c.each { |cc|
    tmp += (cc - i) ** 2
  }
  mn = tmp if mn > tmp
end
puts mn
