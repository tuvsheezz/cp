def gi; gets.to_i; end
def gli; gets.split.map(&:to_i); end

n, m = gli
a = gli
t = 1

tmp = a[0]

while tmp.even? do
  t *= 2
  tmp /= 2
end

m /= t / 2

a = a.map do |ai|
    unless ai % t == 0 && (ai / t) % 2 == 1
      puts 0 
      exit
    end
    ai /= t
end

l = 1

a.each do |ai|
  l = l.lcm(ai)
  if l > m
    puts 0
    exit
  end
end

puts (m / l + 1) / 2

