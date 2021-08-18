def main
  s1 = gs.reverse!
  s2 = gs.reverse!
  s3 = gs.reverse!
  ch = (s1 + s2 + s3).chars.uniq
  if ch.size > 10
    puts "UNSOLVABLE"
    exit
  elsif s1 == s3 || s2 == s3
    puts "UNSOLVABLE"
    exit
  end

  (0..9).to_a.permutation.each do |x|
    next if x[ch.index(s1[-1])] == 0 || x[ch.index(s2[-1])] == 0 || x[ch.index(s3[-1])] == 0
    
    s = 0

    s1.chars.each_with_index do |c, i|
      s += 10 ** i * x[ch.index(c)]
    end

    s2.chars.each_with_index do |c, i|
      s += 10 ** i * x[ch.index(c)]
    end

    s3.chars.each_with_index do |c, i|
      s -= 10 ** i * x[ch.index(c)]
    end

    if s == 0
      puts calc(x, s1, ch)
      puts calc(x, s2, ch)
      puts calc(x, s3, ch)
      exit
    end
  end
  puts "UNSOLVABLE"
end

def calc(x, s, ch)
  n = 0
  s.chars.each_with_index do |c, i|
    n += 10 ** i * x[ch.index(c)]
  end
  n
end

def gs; gets.chomp; end
def gli; gets.split.map(&:to_i); end
def yesno(x); x ? :Yes : :No; end

main()
