def main
  h, w = gli
  c = []
  cols = []
  rows = []
  c = (0..h - 1).map { |_| gli }

  (0..h - 1).each do |i|
    (0..w - 1).each do |j|
      rows[i].nil? ? rows[i] = c[i][j] : rows[i] += c[i][j]
      cols[j].nil? ? cols[j] = c[i][j] : cols[j] += c[i][j]
    end
  end

  (0..h - 1).each do |i|
    (0..w - 1).each do |j|
      print "#{rows[i] + cols[j] - c[i][j]} "
    end
    puts
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
