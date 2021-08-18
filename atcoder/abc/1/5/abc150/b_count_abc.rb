def gs
  gets.chomp
end

gets
s = gs
puts s.scan(/ABC/).count
