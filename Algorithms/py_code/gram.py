# Gram-Schmidt Process for MATH306-001

# vector class
class vector:
	def __init__(self, dimensions):
		self.dim = dimensions

	def set(vlist):
		self.values = list(vlist)

# Computes a projection of vector x onto vector y.
def projXontoY(x, y):


# Returns a list of an orthogonal basis given nonzero basis X.
def gram(X):
	if X.len() == 0:
		print('Error: zero basis')
		return list[-999]
	V = []
	i = 1
	V.append(X[i - 1])
	while i <= X.len():
		for vect in V:




# Main
if __name__ == "__main__":
	dim = int(input('Which dimension are we working in?'))
	size = int(input('How many vectors in the basis?'))
	if size > dim:
		print('# of vectors must be at most the dimension')
	else:
		basis = []
		i = 1
		while i <= dim:
			v = vector(dim)
			v.set([int(n) for n in input('Enter vector ' + str(i) + ': ')])
			basis.append(v)
			i += 1

		result = list(gram(basis))
