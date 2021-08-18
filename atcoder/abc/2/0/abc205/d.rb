def main
  n, q = gli
  a = gli
  c = a.map.with_index { |x, i| x - i - 1 }

  q.times do
    qi = gi
    if c[-1] < qi
      puts qi + n
    else
      l = c.bsearch_index { |x| x >= qi }
      puts a[l] - 1 - (c[l] - qi)
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
