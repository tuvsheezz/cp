def main
  n = gi
  g = (n * 1.08).floor.to_i
  if g < 206
    puts "Yay!"
  elsif g == 206
    puts "so-so"
  else
    puts ":("
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
