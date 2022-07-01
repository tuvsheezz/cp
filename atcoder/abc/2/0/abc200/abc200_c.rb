# C - Ringo's Favorite Numbers 2
# https://atcoder.jp/contests/abc200/tasks/abc200_c

def gli = gets.split.map(&:to_i)

def gi = gets.to_i

n = gi
a = gli

c = Hash.new(0)

a.each { |x| c[x % 200] += 1 }

r = 0

c.values.each do |x|
  r += x * (x - 1) / 2
end

puts r
