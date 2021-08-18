tm = {}
"abcdefghijklmnopqrstuvwxyz".chars.each { |c|
  tm[c] = 0
}
tm["None"] = 0
s = gets.chomp
s.chars.each { |c|
  tm[c] += 1
}
tm.each {|k,v|
  if v == 0
    puts k
    exit
  end
}
