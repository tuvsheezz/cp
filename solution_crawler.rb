require 'mechanize'

agent = Mechanize.new
(35..166).to_a.each do |page|
  page = agent.get("https://codeforces.com/contest/1606/status/B/page/#{page}?order=BY_JUDGED_DESC")
  puts("page#{page}")
  # puts page.content

  page.links_with(dom_class: 'view-source').each do |link|
    puts(link.href)
    solution = agent.get("https://codeforces.com#{link.href}")
    File.write('hahahaha.txt', "https://codeforces.com#{link.href}\n", mode: 'a') if solution.content.include?('log2')
  end
end
