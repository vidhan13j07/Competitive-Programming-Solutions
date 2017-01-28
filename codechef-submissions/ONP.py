n = input()
while n > 0:
	n -= 1
	out = []
	temp = []
	x = raw_input()
	for i in x:
		if i in "+-*/^":
			temp.append(i)
		elif i == ")":
			p = temp.pop()
			out.append(p)
		elif i == "(":
			pass
		else:
			out.append(i)
	print "".join(out)
