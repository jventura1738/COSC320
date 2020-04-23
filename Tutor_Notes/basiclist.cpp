// Justin Ventura Tutor Notes COSC120
#include <iostream>

// List struct.
struct List {
	
	int size;
	int capacity;
	int * listarr;

	// default constructor.
	List() {

		this->listarr = new int[1];
		this->size = 0;
		this->capacity = 1;

	}

	// destructor.
	~List() {

		delete [] this->listarr;

	}

};

// function to double the lists current
// capacity.
void increase_cap(List & list) {

	// increase the capacity by a factor of 2.
	list.capacity *= 2;

	// this will be the new increased array.
	int * listarr2 = new int[list.capacity];

	// copy over the old to the new list.
	for (int i = 0; i < list.size; i++) {

		listarr2[i] = list.listarr[i];

	}

	// delete the old array.
	delete [] list.listarr;

	// assign the new array to the list struct.
	list.listarr = listarr2;

}

// push a value to the front.
void push_front(List & list, int val) {

	// special case.
	if (list.size == list.capacity) {

		increase_cap(list);

	}

	// allocate the new array.
	int * listarr2 = new int[list.capacity];

	// shift the new array over by 1 to the right.
	for (int i = 1; i < list.size + 1; i++) {

		listarr2[i] = list.listarr[i - 1];

	}

	// deallocate the old array.
	delete [] list.listarr;

	// assign the struct array to the newly allocated.
	list.listarr = listarr2;

	// now push val onto the front...
	// [0 0 1 2 3 X] -> [5 0 1 2 3 X]
	list.listarr[0] = val;
	list.size++;

}

// push a value to the back.
void push_back(List & list, int val) {

	// special case.
	if (list.size == list.capacity) {

		increase_cap(list);

	}

	// list.size is the last element, after
	// appending val, size increments.
	list.listarr[list.size] = val;
	list.size++;

}

// remove the front value and return it.
int pop_front(List & list) {

	// we will return this.
	int popval = list.listarr[0];

	// allocate the new array.
	int * listarr2 = new int[list.capacity];

	// shift over by 1 to the left.
	for (int i = 0; i < list.size - 1; i++) {

		listarr2[i] = list.listarr[i + 1];

	}

	// deallocate the old array.
	delete [] list.listarr;

	// assign the struct array to the newly allocated.
	list.listarr = listarr2;

	// the size must now decrement.
	list.size--;

	// return the front.
	return popval;

}

// returns the value from the back of the
// given list and removes it.
int pop_back(List & list) {

	// return the last value, then decrement
	// the size.
	list.size--;
	return list.listarr[list.size];

}

// function to print the list.
void printlist(List & list) {

	// print all elements in the list:
	std::cout << "[ ";
	for (int i = 0; i < list.size; i++) {

		std::cout << list.listarr[i] << " ";

	}
	std::cout << "]\n";

}


int main() {
	
	// create the list.
	List l;

	// Test the push back.
	std::cout << "Pushing back 5.\n";
	push_back(l, 5);
	std::cout << "Pushing back 7.\n";
	push_back(l, 7);
	std::cout << "Pushing back 9.\n";
	push_back(l, 9);
	std::cout << "Current capacity: " << l.capacity << "\n";
	std::cout << "Current list elements: ";
	printlist(l);
	std::cout << "\n";

	// Test the push front.
	std::cout << "Pushing front 3.\n";
	push_front(l, 3);
	std::cout << "Pushing front 1.\n";
	push_front(l, 1);
	std::cout << "Pushing front 0.\n";
	push_front(l, 0);
	std::cout << "Current capacity: " << l.capacity << "\n";
	std::cout << "Current list elements: ";
	printlist(l);
	std::cout << "\n";

	// Test the pop back & front.
	std::cout << "Popping front: " << pop_front(l) << ".\n";
	std::cout << "Current list elements: ";
	printlist(l);
	std::cout << "Popping back: " << pop_back(l) << ".\n";
	std::cout << "Current list elements: ";
	printlist(l);
	std::cout << "Current capacity: " << l.capacity << "\n";
	std::cout << "\n";

	return 0;
}
