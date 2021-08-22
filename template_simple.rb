def solve
  s = gets.chomp.split('')
  permutations = s.permutation.uniq.sort
  permutations.each do |per|
    flag = true
    per.each.with_index do |c, i|
      flag = false if s[i] == c
    end
    if flag
      puts per.join
      return
    end
  end
  puts "IMPOSSIBLE"
end

def main
  gets.to_i.times { solve }
end

main