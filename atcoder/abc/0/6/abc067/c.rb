def main
  n = gi
  a = gli
  s = a.sum
  c = a[0]
  m = (c - (s - c)).abs
  for i in 1..n-2
    c += a[i]
    t = (c - (s - c)).abs
    m = t if m > t
  end
  puts m
end

INF = 10 ** 16
MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end

main()