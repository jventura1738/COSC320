# Justin Ventura 
# COSC320 (02/04/20)

# For compatability with Python 2:
from __future__ import print_function


# Function D(n):
def D(n):
	s = 0
	i = 0 

	count = [0, 0, 0, n]

	while i < (n * n): 
		count[0] += 1
		s = s + i 
		j = i

		while j > 0: 
			count [1] += 1
			s = s / 2
			j = j - 5

		i += 2

	count[2] = (count[0] * count[1])
	return count

for i in range(1, 26):
	testcount = D(i)
	print(testcount)

