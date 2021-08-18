def main
  n, k = gli
  d = gli
  
  while true do
    if n.to_s.split('').map(&:to_i).any? { |k| d.include? k }
      n += 1
    else
      puts n
      exit
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
