def gi
gets.to_i
end

def gli
  gets.split.map(&:to_i)
end

n = gi

ml = {}

n.times do
  k, v = gets.chomp.split
  ml[k] = v.to_i
end

ml = ml.sort_by { |_k, v| v }

puts ml[-2][0]
