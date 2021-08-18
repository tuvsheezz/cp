def main
  _, a, b = gli
  s = gs
  p1 = 0
  p2 = 0
  s.each_char do |c|
    if c == 'a' && p1 < a + b
      p1 += 1
      puts 'Yes'
    elsif c == 'b' && p1 < a + b && p2 < b
      p1 += 1
      p2 += 1
      puts 'Yes'
    else
      puts 'No'
    end
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
