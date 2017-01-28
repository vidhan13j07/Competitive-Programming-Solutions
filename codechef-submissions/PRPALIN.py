def isPalindrome(n):
    i = 0
    s = str(n)
    j = len(s)-1
    while i<j:
        if (s[i] != s[j]):
            return False
        else:
            i += 1
            j -= 1
    return True
def isPrime(n):
    if (n == 2 or n == 3):
        return True
    if (n < 2 or n % 2 == 0 or n%3==0):
        return False
    if (n < 9):
        return True
    for f in xrange(5,int(n**0.5),6):
        if (n % f == 0) or (n%(f+2) == 0):
            return False
        f +=6
    return True
n = int(raw_input())
if n % 2 == 0:
    n=n+1
while(True):
    if isPalindrome(n):
        if isPrime(n):
            print n
            break
    n=n+2
