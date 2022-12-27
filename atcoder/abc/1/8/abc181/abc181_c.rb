n = gets.to_i
p = []
n.times { p << gets.split.map(&:to_i) }

def find(n, p)
  0.upto(n - 3) do |i|
    (i + 1).upto(n - 2) do |j|
      (j + 1).upto(n - 1) do |k|
        return 'Yes' if (p[i][1] - p[j][1]) * (p[i][0] - p[k][0]) == (p[i][0] - p[j][0]) * (p[i][1] - p[k][1])
      end
    end
  end
  'No'
end

puts find(n, p)
