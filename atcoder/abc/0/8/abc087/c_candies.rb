def main
  h = 2
  w = gi
  g = []
  h.times { g << gli }
  for i in (0..h-1)
    for j in (0..w-1)
      g[i][j] += g[i][j-1] if j > 0 && i == 0
      g[i][j] += g[i-1][j] if i > 0 && j == 0
      g[i][j] += [g[i-1][j], g[i][j-1]].max if i > 0 && j > 0
    end
  end
  puts g[h-1][w-1]
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
