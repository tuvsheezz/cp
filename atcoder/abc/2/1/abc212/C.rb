MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); puts x ? :Yes : :No; end
def uyesno(x); puts x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  n, m = gli
  aa = gli.sort
  ba = gli.sort
  a = 0
  b = 0
  s = [aa[-1] - ba[0], ba[-1] - aa[0]].max
  while a < n and b < m
    k = (aa[a] - ba[b]).abs
    s = k if k < s
    if aa[a] < ba[b]
      a += 1
    else
      b += 1
    end
  end
  puts s
end

main
