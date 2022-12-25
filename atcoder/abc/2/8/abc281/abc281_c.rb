_, t = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

to = a.inject(:+)
r = t % to

a.each_with_index do |dur, i|
  if dur >= r
    puts [i + 1, r].join(' ')
    break
  end
  r -= dur
end
