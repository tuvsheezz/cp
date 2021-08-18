n, k = gets.split.map(&:to_i)

for i in 0..n
  for j in 0..n-i
    if i * 10000 + j * 5000 + (n-i-j) * 1000 == k
      puts "#{i} #{j} #{n-i-j}"
      exit
    end
  end
end

puts "#{-1} #{-1} #{-1}"
