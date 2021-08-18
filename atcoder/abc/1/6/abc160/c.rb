MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); puts x ? :Yes : :No; end
def uyesno(x); puts x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  k, n = gli
  a = gli
  d = [a[0] + k - a[-1]]
  for i in (1..n - 1)
    d << a[i] - a[i - 1]
  end
  puts k - d.max
end

main
