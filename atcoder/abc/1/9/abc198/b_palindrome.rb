def main
  s = gs
  puts yesno(s.reverse.to_i == s.reverse.to_i.to_s.reverse.to_i)
end

def gs; gets.chomp; end
def yesno(x); x ? :Yes : :No; end

main()
