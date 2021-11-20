def solution(s)
  # 任意の数値なので.や-が複数含まれてないものとする。
  s = s.to_s.split('')
  # 空の場合や'.'だけの場合0を戻す
  return '0' if s.empty? || s.join == '.'

  # 負の整数場合先頭の'-'消す
  minus = false
  if s[0] == '-'
    minus = true
    s.shift
  end
  # '-'を消した後、空の場合や'.'だけの場合0を戻す
  return '0' if s.empty? || s.join == '.'

  d = s.find_index('.')
  unless d.nil?
    # '.'の位置が一番前なら先頭に0を付ける
    if d.zero?
      s.unshift('0')
      d += 1
    end
    # '.'で終わってる場合、後ろに0を付けるもあり得るが指定されてないので'.'を消す。
    if d == s.length - 1
      s.pop
      d -= 1
    end
  end
  # 整数部分の桁数 k(整数の場合はsの長さ)
  k = d || s.length
  # '.'前から3桁ずつ','を追加していく。
  (1..k).each do |i|
    next if s[k - i] == '-' || k == i

    s[k - i] = ",#{s[k - i]}" if (i % 3).zero?
  end
  # 負の整数場合先頭に'-'を付ける
  s.unshift('-') if minus

  s.join
end
