# https://atcoder.jp/contests/abc192/tasks/abc192_c

def gli; gets.split.map(&:to_i); end

def func(n)
  g2 = n.to_s.chars.sort.join
  g1 = g2.reverse
  g1.to_i - g2.to_i
end

n, k = gli

k.times do
  n = func(n)
end

puts n