def gs() = gets.chomp
def gi() = gets.to_i
def gli() = gets.split.map(&:to_i)
def cyesno(x) = x ? :Yes : :No
def uyesno(x) = x ? :YES : :NO

gets
s = gets.chomp.split('')
k = gets.to_i
puts s.map { |x| x != s[k - 1] ? '*' : x  }.join
  