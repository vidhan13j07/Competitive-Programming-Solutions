s = raw_input()
a,b = s.split('e')
c,d = a.split('.')
b = int(b)
s = ""
if d.count('0') == len(d):
    if c == '0':
        s += '0'
    else:
        s += c + '0'*b
elif b == 0:
	s += a
elif b == len(d):
    if c != '0':
        s += c
    s += d
elif b > len(d):
    if c != '0':
        s += c
    s += d + '0'*(b - len(d))
else:
    if c != '0':
        s += c
    s += d[:b] + '.' + d[b:]
print s
