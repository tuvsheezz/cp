MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); puts x ? :Yes : :No; end
def uyesno(x); puts x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  _ = gi
  a = gli
  c = array_to_hash_by_count(a).map { |k, v| [k, v] if v >= 2 }.compact.sort { |a, b| a[0] <=> b[0] }
  if c.empty? || c.length == 1 && c[0][1] < 4
    puts 0
  else
    if c[-1][1] >= 4
      puts c[-1][0] ** 2
    else
      puts c[-1][0] * c[-2][0]
    end
  end
end

main