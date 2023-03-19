def fu
  if @a.size == @n
    puts @a.join(' ')
    return
  end
  return if @a[-1] == @m
  
  (@a[-1] + 1..@m).each do |i|
    @a.push(i)
    fu()
    @a.pop
  end
end

@a = []
@n, @m = gets.split.map(&:to_i)
(1..@m).each do |x|
  @a.push(x)
  fu
  @a.pop
end
