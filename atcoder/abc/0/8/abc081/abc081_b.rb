n = gets.to_i
a = gets.split.map(&:to_i)

ret = 0

while true
  for i in 0..n-1
    if a[i].odd?
      puts ret
      exit
    end
    a[i] /= 2
  end
  ret += 1
end
