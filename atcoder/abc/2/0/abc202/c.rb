def main
  n = gi
  a = gli
  b = gli
  c = gli
  r = 0
  d = []
  0.upto(n-1) do |i|
    d << b[c[i] - 1]
  end

  ad = Hash.new(0).tap { |h| a.each { |x| h[x] += 1 } }
  dd = Hash.new(0).tap { |h| d.each { |x| h[x] += 1 } }

  ad.each do |k, v|
    r += dd[k] * v
  end
  
  puts r
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end

main()
