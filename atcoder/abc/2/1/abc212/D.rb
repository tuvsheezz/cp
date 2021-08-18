MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); puts x ? :Yes : :No; end
def uyesno(x); puts x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  a = []
  mn = 0
  gi.times do
    q, w = gli
    if q == 1
      a << w - mn
    elsif q == 2
      mn += w
    elsif a.any?
      d = a.min
      a[a.index(d)] = Float::INFINITY
      puts d + mn
    end
  end
end

main
