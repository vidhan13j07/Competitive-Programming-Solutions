l=raw_input().split()
day = int(l[0])
if l[-1]=='month':
    if day <= 29:
        print '12'
    elif day == 30:
        print '11'
    else:
        print '7'
else:
    if day == 5 or day == 6:
        print '53'
    else:
        print '52'