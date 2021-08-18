def main
  a, b, c = gli
  if c.odd?
    if a == b
      puts '='
    elsif a > b
      puts '>'
    else
      puts '<'
    end
  else
    a = a.abs
    b = b.abs
    if a == b
      puts '='
    elsif a > b
      puts '>'
    else
      puts '<'
    end
  end
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def glf; gets.split.map(&:to_f); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
