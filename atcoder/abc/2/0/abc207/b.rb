def main
  a, b, c, d = gli
  a += b
  y = c
  xx_last = a / y
  count = 1
  while true do
    if a <= y * d
      puts count
      return
    end
    xx_tmp = a / y
    if xx_last < xx_tmp
      puts -1
      return
    end
    a += b
    y += c
    count += 1
    xx_last = xx_tmp
  end
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
