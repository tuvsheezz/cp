puts gets.strip.split('').map(&:to_i).sum % 9 == 0 ? 'Yes' : 'No'
