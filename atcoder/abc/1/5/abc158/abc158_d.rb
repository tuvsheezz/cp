s = gets.chomp
q = gets.to_i
ir = false
tl = []
hd = []
q.times {
  q = gets.chomp.split(" ")
  if q[0] == "1"
    ir = !ir
  else
    if q[1] == "1"
      if ir == false
        hd << q[2]
      else
        tl << q[2]
      end
    else
      if ir == false
        tl << q[2]
      else
        hd << q[2]
      end
    end
  end
}

s = hd.join("").reverse + s + tl.join("")
puts ir == false ? s : s.reverse
