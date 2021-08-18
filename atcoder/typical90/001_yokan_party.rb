def main
  n, l = gli
  k = gi
  x = gli
  x.unshift(0)

  left = -1
  right = l + 1
  while right > left + 1 do
    mid = left + (right - left) / 2
    if solve(mid, n, x, l, k)
      left = mid
    else
      right = mid
    end
  end
  puts left
end

def solve(mid, n, x, l, k)
  count = 0
  pre = 0
  for i in 1..n do
    if x[i] - pre >= mid && l - x[i] >= mid
      count += 1
      pre = x[i]
    end
  end
  return true if count >= k

  false
end


MOD = 10 ** 9 + 7
def gs; gets.chomp; end
def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end
def cyesno(x); x ? :Yes : :No; end
def uyesno(x); x ? :YES : :NO; end
def array_to_hash_by_count(c); Hash.new(0).tap { |x| c.each { |z| x[z] += 1 } }; end

main()
