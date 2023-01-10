gets.to_i.times do
  n, x = gets.split.map(&:to_i)

  mx = 0
  63.times do |i|
    if x % 2 != n % 2
      mx = [mx, ].min
    end
  end
end