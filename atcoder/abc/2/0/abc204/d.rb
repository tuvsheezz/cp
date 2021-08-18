def main
  n = gi
  x = gli.sort.reverse
  o1 = 0
  o2 = 0
  if n == 1
    puts x[0]
  else
    o1 = x[0]
    o2 = x[1]

    for i in 2..n - 1
      o1 < o2 ? o1 += x[i] : o2 += x[i]
    end

    puts [o1, o2].max
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
