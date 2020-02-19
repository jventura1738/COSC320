# Justin Ventura
# 02/19/20

import exceptions

class Matrix:

	def __init__ (self):
		self.row = 0
		self.col = 0

MatMult(A, B):
	if A.col != B.row:
		raise "you done fucked up"

	for i in range(0, A.row):

		for j in range(0, B.col):

			C[i][j] = 0

			for k in range (0, A.col):

				C[i][j] = A[i][k]*B[k][j]
