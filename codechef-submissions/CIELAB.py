a,b=map(int,raw_input().split())
print abs(a-b)+1 if abs(a-b)%10!=9 else abs(a-b)-1
