def chck(s, t)
  for i in 0..s.size-1
    for j in 0..s.size-1
      if (s[i] == s[j] && t[i] != t[j]) || (s[i] != s[j] && t[i] == t[j])
        return false
      end
    end
  end
  return true
end
n = gets.to_i
chrs = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l"]

l = ["a"]

for i in 1..n-1
  tmp = []
  l.each do |ll|
    for k in 0..ll.split("").uniq.size
        tmp << ll + chrs[k]
    end
  end
  tmp << l[-1] + chrs[i]
  l = tmp.dup
end

puts l.uniq.sort

