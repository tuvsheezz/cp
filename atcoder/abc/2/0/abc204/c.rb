E = {}
def main
  n, m = gli
  m.times do
    s, t = gli
    E[s] ? E[s] << t : E[s] = [t]
  end

  ans = n

  E.each do |k, v|
    visited = [k]
    ans += go_next(k, visited)
  end
  puts ans
end

def go_next(k, visited)
  r = 0
  E[k].each do |q|
    next if visited.include? q

    r += 1
    visited << q
    r += go_next(q, visited)
  end
  return r
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
