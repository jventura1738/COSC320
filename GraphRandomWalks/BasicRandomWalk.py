# Justin Ventura COSC320 
# Project 3: BasicRandomWalk.py

import numpy as np
import matplotlib.pyplot as plt

# Demonstrate a very basic random walk and
# Provide formal analysis on it.

def basicwalk(runs, pos, bdata):
	# Simulate the walk & collect data.
	cursor = 0
	for elem in runs:
		if elem == 0:
			cursor -= 1
		else:
			cursor += 1
		pos.append(cursor)
		if cursor not in bdata:
			bdata[cursor] = 1
		else:
			bdata[cursor] += 1


if __name__ == '__main__':
	# This will keep track of how many iterations to compute.
	trials = int(input('Enter number of random iterations: '))

	# Keep track of the positions & data for bar graph.
	positions = []
	bardata = {0:0}

	# Run the actual random walk on R1.
	runs = np.random.randint(2, size=trials)
	basicwalk(runs, positions, bardata)

	# Terminal data (check vs bar graph)
	print('Positions after each iteration: ', positions)
	print('Bar data to be graphed: ', bardata)
	bardataX, bardataY = zip(*bardata.items())
	print('Values on the X axis:   ', bardataX)
	print('Respective bar heights: ', bardataY)

	# Display the bar graph.
	plt.bar(bardataX, bardataY, align='center')
	plt.show()


