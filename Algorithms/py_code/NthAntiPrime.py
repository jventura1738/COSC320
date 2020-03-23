# Justin Ventura 03/15/20
# Program to calculate the
# Nth Anti-Prime

# --> CODING SECTION <--
# Seq: 1,2,4,6,12,24,36

def divisorsOf(n):
	divisors = 0
	for i in range(1,n+1):
		if n % i == 0:
			divisors +=1
	return divisors

def isAntiPrime(n):
	for i in range(1,n):
		if divisorsOf(i) >= divisorsOf(n):
			return False
	return True

def NthAntiPrime(N):
	if N == 1:
		return 1
	elif N == 2:
		return 2
	APval = 4
	APnum = 2
	while 1:
		if isAntiPrime(APval):
			APnum += 1
		if APnum == N:
			return APval
		APval += 2

# --> TESTING SECTION <--

for N in range(1,21):
	print(N, NthAntiPrime(N))

