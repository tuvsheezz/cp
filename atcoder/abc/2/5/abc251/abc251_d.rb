_ = gets.to_i
ans = []

(1...100).each do |q|
  ans << q if q <= 10**6
  ans << q * 100 if q * 100 <= 10**6
end
(1..100).each do |q|
  ans << q * 100 * 100 if q * 100 * 100 <= 10**6
end

ans.sort!
puts ans.uniq.size
puts ans.uniq.join(' ')
