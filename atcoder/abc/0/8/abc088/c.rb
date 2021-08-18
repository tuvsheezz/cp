def main
  c = []
  3.times { c << gli }
  b = c[0]
  a = c.map { |x| x[0] - b[0] }
  f = true
  for i in 0..2
    for j in 0..2
      f = false unless c[i][j] == a[i] + b[j]
    end
  end

  puts cyesno(f)
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end

main()