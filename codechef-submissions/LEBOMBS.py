t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    S = raw_input()
    count = 0
    for i in xrange(1, n - 1):
        if S[i] == '0' and S[i - 1] == '0' and S[i + 1] == '0':
            count += 1
    if n != 1:
        if S[0] == '0' and S[1] == '0':
            count += 1
        if S[n - 1] == '0' and S[n - 2] == '0':
            count += 1
    else:
        if S[0] == '0':
            count = 1
    print count
