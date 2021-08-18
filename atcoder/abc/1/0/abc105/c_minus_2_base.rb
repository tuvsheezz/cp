def main
  n = gets.to_i
  s = "1"
  e = 0
  if n.zero?
    "0"
  elsif n.positive?
    c = 0
    while c < n.abs do
      c += 2 ** e if e.even?
      e += 1
    end
  else
    c = 0
    while c < n.abs do
      c += 2 ** e if e.odd?
      e += 1
    end
  end
  n -= (-2) ** (e - 1)
  # (e-2).downto(0) do |i|
  #   puts (-2) ** i
  #   if n.zero?
  #     s += '0'
  #   elsif n > 0

  #   end
  # end
  puts n
end

def next_digit(n)

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
