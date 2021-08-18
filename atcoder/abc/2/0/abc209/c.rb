def main
  n = gi
  c = gli.sort
  c = c.map.with_index { |x, i| [x - i, 0].max }
  d = 1
  c.each do |x|
    d = (d * x) % MOD
  end

  puts d
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
