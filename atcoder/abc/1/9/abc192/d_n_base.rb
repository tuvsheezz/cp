# https://atcoder.jp/contests/abc192/tasks/abc192_d

def base_n(n, base)
  n.inject(0) { |d, x| d * base + x }
end

x = gets.chomp.chars.map(&:to_i)
m = gets.to_i

if x.size == 1
  p x[0] <= m ? 1 : 0
  exit
end

bl = 0
br = 10**18 + 1

while bl + 1 < br
  md = (bl + br) / 2
  if base_n(x, md) <= m
    bl = md
  else
    br = md
  end
end

puts [0, bl - x.max].max
