a = gets.strip.split('').map(&:to_i).map { |i| i % 3 }

r = (a.count(1) % 3 - a.count(2) % 3).abs
r1 = (a.count(1) - a.count(2)).abs % 3

r = r1 if r > r1

if a.size == r
  puts -1
else
  puts r
end
