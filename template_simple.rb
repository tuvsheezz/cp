MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); puts x ? :Yes : :No; end
def uyesno(x); puts x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

c = 0
s, t = gli
for i in (0..s+1)
  for j in (0..s+1)
    for k in (0..s+1)
      c+=1 if i + j + k <= s && i * j * k <= t
    end
  end
end
puts c
