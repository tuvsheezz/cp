gets
puts gets.split.select.with_index { |x, i| x.to_i.odd? && i.even? }.size