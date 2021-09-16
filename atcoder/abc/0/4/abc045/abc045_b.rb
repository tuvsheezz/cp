H = {}
H["a"] = gets.chomp.split("")
H["b"] = gets.chomp.split("")
H["c"] = gets.chomp.split("")
cur = "a"

while true do
  break if H[cur]&.empty?
  cur = H[cur].shift
end

puts cur.upcase