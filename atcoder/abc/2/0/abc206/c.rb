def main
  n = gi
  a = gli
  c = array_to_hash_by_count(a)

  d = c.map { |x, y| [x, y] }

  r = 0

  for i in 0..d.size - 1 do
    r += (n - d[i][1]) * d[i][1]
  end
  puts r / 2
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
