def main
  s = gs.reverse
  s.chars.each_with_index do |x, i|
    if x == '6'
      s[i] = '9'
    elsif x == '9'
      s[i] = '6'
    end
  end
  puts s
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end

main()
