gets
a = gets.split.map(&:to_i)
mx = a[0]
ans = 0
a.each_with_index do |_k, i|
  if mx < a[i]
    mx = a[i]
    ans = i
  end
end
puts ans + 1
