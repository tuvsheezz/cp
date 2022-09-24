def solve
  _, k = gets.split.map(&:to_i)
  s = gets.split.map(&:to_i).tally
  q = 0
  s.each_value do |v|
    return false if v > 2

    q += v
  end
  q <= 2 * k
end

gets.to_i.times do |i|
  f = solve
  puts "Case ##{i + 1}: #{f ? 'YES' : 'NO'}"
end
