gets
puts gets.split.map { |x| x.to_i % 2 }.count(1) % 2 == 0 ? 'YES' : 'NO'
