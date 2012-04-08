#Dead simple ruby script to split function names from tracer output
#WARNING: not well debugged (may omit functions under rare circumstances)
#For C++, post process by piping into "c++filt -n"
#Ben Matthews <ben@kc2vjw.com>


f = File.open(ARGV[0], 'r')
f.each_line do |l|
	puts l.match(/(funcall)(.*)(0x[0-9a-f]*)([ ])(.*)([ ])(\+)(.*)$/)[5]
end
$stdout.flush
f.close
