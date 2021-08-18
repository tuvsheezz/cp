def gi
  gets.to_i
 end
 
 def gli
   gets.split.map(&:to_i)
 end
 
a = gli.sort
b = []

for i in 0..a.size - 2 do
  b << a[i+1] - a[i]
end

puts b.uniq.size == 1 ? :Yes : :No
