def main
  r = ""
  0.upto(2) do |x|
    r += gs[x]
  end

  puts r
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end
def combination(n, m)
  if m < 0 || n < m
    0
  else
    c = ((n - m + 1)..n).reduce(1, :*)
    (1..m).reduce(c, :/)
  end
end

main()
