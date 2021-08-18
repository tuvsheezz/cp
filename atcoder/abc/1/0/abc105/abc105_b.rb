n = gets.to_i
f = false
for i in 0..n/4
  f = true if (n-4*i)%7 == 0
end

puts f ? "Yes" : "No"
