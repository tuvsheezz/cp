def gs() = gets.chomp
def gi() = gets.to_i
def gli() = gets.split.map(&:to_i)
def cyesno(x) = x ? :Yes : :No
def uyesno(x) = x ? :YES : :NO
x, y, z = gli
y += 24 if x >= y

puts cyesno(x <= z && z < y)