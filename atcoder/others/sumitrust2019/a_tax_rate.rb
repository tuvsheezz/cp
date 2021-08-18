def main
  n = gets.to_i
  d = (n * 100..n * 100 + 99).map { |x| x if x % 108 == 0 }.compact
  if d.length.zero?
    puts ':('
  else
    puts d[0] / 108
  end
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
