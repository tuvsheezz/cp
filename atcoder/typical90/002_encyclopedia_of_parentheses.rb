def main
  n = gi
  
  0.upto((1 << n) / 2) do |i|
    s = ''
    (n-1).downto(0) do |j|
      if (i & (1 << j)) == 0
        s += '('
      else
        s += ')'
      end
    end
    puts s
    puts s if check(s)
  end
end

def check(s)
  v = 0
  s.each_char do |c|
    v += 1 if c == '('
    v -= 1 if c == ')'
    return false if v < 0
  end
  return true if v.zero?
  false
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
