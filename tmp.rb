def gs() = gets.chomp
def gi() = gets.to_i
def gli() = gets.split.map(&:to_i)
def cyesno(x) = x ? :Yes : :No
def uyesno(x) = x ? :YES : :NO

T = gi
T.times do
  s = gets.chomp.split("").map(&:to_i)
  if s.count { |x| x.even? }.zero?
    puts '-1'
  else
    if s[-1].even?
      puts 0
    elsif s[0].even?A
      puts 1
    else
      puts 2
    end
  end
end