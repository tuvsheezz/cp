def main
  a = 5
  a, b, ind = gli
  s = ""
  (a + b).times do
    c = combination(a + b - 1, [a - 1, b].min)
    if ind <= c
      s += 'a'
      a -= 1
    else
      ind -= c
      s += 'b'
      b -= 1
    end
  end

  puts s
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def combination(n, m)
  if m < 0 || n < m
    0
  else
    c = ((n - m + 1)..n).reduce(1, :*)
    (1..m).reduce(c, :/)
  end
end

main()
