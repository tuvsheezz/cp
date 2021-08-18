def main
  gets
  puts gli.sort.reverse.map.with_index { |ai, i| i.even? ? ai : -ai }.sum
end

MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end

main()