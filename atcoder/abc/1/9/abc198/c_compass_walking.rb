def main
  n, x, y = gli
  d = Math.sqrt(x * x + y * y)
  puts d < n ? 2 : (d.to_f/n).ceil
end

def gs; gets.chomp; end
def gli; gets.split.map(&:to_i); end
def yesno(x); x ? :Yes : :No; end

main()
