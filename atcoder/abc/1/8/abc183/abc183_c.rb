@n, @k = gets.split.map(&:to_i)
@t = []
@n.times do
  @t << gets.split.map(&:to_i)
end

def travel(cost = 0, visited = [0])
  if visited.size == @n
    return 1 if cost + @t[visited[-1]][0] == @k

    return 0
  end

  ret = 0
  0.upto @n - 1 do |i|
    next if visited.include? i

    ret += travel(cost + @t[visited[-1]][i], visited + [i])
  end
  ret
end

p travel
