n = gets.to_i

ac = 0
wa = 0
tle = 0
re = 0

n.times do
  case gets.chomp
  when 'AC'
    ac += 1
  when 'WA'
    wa += 1
  when 'TLE'
    tle += 1
  else 'RE'
    re += 1
  end
end

puts "AC x #{ac}"
puts "WA x #{wa}"
puts "TLE x #{tle}"
puts "RE x #{re}"
