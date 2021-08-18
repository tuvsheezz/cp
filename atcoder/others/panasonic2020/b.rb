MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  h, w = gli

  if h == 1 || w == 1
    puts 1
  else
    puts h / 2 * w + (h % 2) * (w + 1) / 2
  end
end

main
