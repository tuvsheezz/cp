# B - 200th ABC-200 https://atcoder.jp/contests/abc200/tasks/abc200_b

def gli
  gets.split.map(&:to_i)
end

n, k = gli

k.times do
  if n % 200 == 0
    n = n / 200
  else
    n = n * 1000 + 200
  end
end

puts n