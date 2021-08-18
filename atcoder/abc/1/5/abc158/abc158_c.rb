def gli
  gets.split.map(&:to_i)
end

e, t = gli

i = 0
while 1
  i += 1
  if i * 8 / 100  == e && i / 10 == t
    puts i
    exit
  end
  if i > 10000
    puts -1
    exit
  end
end
