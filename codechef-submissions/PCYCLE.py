n = input()
a = map(int, raw_input().split())
c = 0
t = []
t2 = []
while sum(a) != 0:
    j = 1
    for i in range(len(a)):
        if a[i] != 0:
            j = i
            break
    
    while a[j] != 0:
        d = a[j]
        t.append(str(j+1))
        a[j] = 0
        j = d - 1
    c += 1
    t.append(str(j + 1))
    t2.append(t)
    t = []
print c
 
for i in t2:
    print ' '.join(i)
