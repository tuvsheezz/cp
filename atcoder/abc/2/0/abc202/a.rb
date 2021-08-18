def main
  a, b, c = gli
  puts 21 - a - b - c 
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end

main()
