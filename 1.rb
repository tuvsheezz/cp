def createtest
  File.open('1.txt', 'w') do |file|
    file.write("10000\n")
    10000.times do
      file.write("200\n")
      200.times do |i|
        file.write(rand(1..10000000))
        if i == 199
          file.write("\n")
        else
          file.write(" ")
        end
      end
    end
  end
end

def createtest2
  puts 10000
  10000.times do
    puts 200
    200.times do |i|
      print rand(1..10000000)
      if i == 199
        print "\n"
      else
        print " "
      end
    end
  end
end
createtest