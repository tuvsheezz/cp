MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); puts x ? :Yes : :No; end
def uyesno(x); puts x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  a = gs.split('').map(&:to_i)
  if a.uniq.length == 1
    puts 'Weak'
  elsif (a[0] + 1) % 10 == a[1] && (a[1] + 1) % 10 == a[2] && (a[2] + 1) % 10 == a[3]
    puts 'Weak'
  else
    puts 'Strong'
  end
end

main
