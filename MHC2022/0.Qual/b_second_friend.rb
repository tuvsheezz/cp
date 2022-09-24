def solve(t_case)
  n, m = gets.split.map(&:to_i)
  a = []
  n.times { a << gets.chomp }
  tc = a.join.count('^')
  if n == 1 || m == 1
    if tc != 0
      puts "Case ##{t_case}: Impossible"
    else
      puts "Case ##{t_case}: Possible"
      puts a.join("\n")
    end
  else
    puts "Case ##{t_case}: Possible"
    puts (['^' * m] * n).join("\n")
  end
end

gets.to_i.times do |i|
  solve(i + 1)
end
