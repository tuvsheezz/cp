n = gets.to_i
a = gets.chomp.split.map(&:to_i)
a.uniq!
a.sort!

(0...(a.size)).each do |i|
  if i != a[i]
    puts i
    return
  end
end
puts a.size
