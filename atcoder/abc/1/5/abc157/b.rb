MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

def main
  a = []
  3.times { a += gli }
  n = gi
  n.times do
    x = gi
    a[a.index(x)] = 0 if a.include?(x)
  end
  fl = false
  fl = true if a[0] == 0 && a[1] == 0 && a[2] == 0
  fl = true if a[3] == 0 && a[4] == 0 && a[5] == 0
  fl = true if a[6] == 0 && a[7] == 0 && a[8] == 0
  fl = true if a[6] == 0 && a[3] == 0 && a[0] == 0
  fl = true if a[7] == 0 && a[4] == 0 && a[1] == 0
  fl = true if a[8] == 0 && a[5] == 0 && a[2] == 0
  fl = true if a[0] == 0 && a[4] == 0 && a[8] == 0
  fl = true if a[2] == 0 && a[4] == 0 && a[6] == 0
  puts cyesno(fl)
end

main
