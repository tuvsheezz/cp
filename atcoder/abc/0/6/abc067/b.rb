def main
  _, k = gli
  a = gli.sort.reverse

puts a[0..k-1].sum
end

INF = 10 ** 16
MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end

main()