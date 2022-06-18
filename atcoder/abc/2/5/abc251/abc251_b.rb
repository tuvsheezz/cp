n, w = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

q = []

(0...n).each do |i|
  q << a[i]
  (i + 1...n).each do |j|
    q << a[i] + a[j]
    (j + 1...n).each do |k|
      q << a[i] + a[j] + a[k]
    end
  end
end
ans = 0
q.uniq.each do |x|
  ans += 1 if x <= w
end

puts ans
