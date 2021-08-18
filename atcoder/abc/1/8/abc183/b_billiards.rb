sx, sy, gx, gy = gets.split.map(&:to_f)
sx, sy, gx, gy = gx, gy, sx, sy if gx < sx
puts((sx * gy + gx * sy) / (sy + gy))
