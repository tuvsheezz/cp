# frozen_string_literal: true

_, x = gets.split.map(&:to_i)
s = gets.chomp

s.split('').each do |c|
  if c == 'o'
    x += 1
  else
    x -= 1
  end
  x = 0 if x.negative?
end

p x
