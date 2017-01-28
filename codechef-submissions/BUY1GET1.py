import sys
 
def main():
	t = int(sys.stdin.readline())
 
	for i in range(0, t):
		countMap = {}
		input = sys.stdin.readline().strip()
		
		for j in input:
			if(j in countMap):
				countMap[j] = countMap[j] + 1
			else:
				countMap[j] = 1
				
		ans = 0
		for j in countMap:
			ans = ans + (countMap[j] / 2) + (countMap[j] % 2)
		
		print ans			
main()
