n = gets.to_i
s = gets.chomp
q = gets.to_i
q.times {
  w = gets.chomp.split(" ")
  if w[0] == "1"
    s[w[1].to_i] = w[2]
  else
    puts s[w[1].to_i-1..w[2].to_i-1].split("").uniq.size
  end
}
