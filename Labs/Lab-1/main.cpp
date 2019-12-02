#include <iostream>
#include <chrono>
#include <random>
#include "helpers.h"

// enum for array ordering
enum element_order { RANDOM = 0, ASCEND, DESCEND };

int * arrayGenerate (element_order ORDER, int len);

// tests a given sort, reports time, swaps, etc
void testSort(void (*sort)(int*, int), int* arr, int n);

int main()
{
	int * arr = arrayGenerate(RANDOM, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	bubbleSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	return 0;
}

int * arrayGenerate (element_order ORDER, int size)
{
    int * array = new int[size];
    if (ORDER == RANDOM)
    {
        for (int i = 0; i < size; i++)
        {
            *(array + i) = (i + 1);
        }
        // generates a random seed for the random engine
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(array, array + size, std::default_random_engine(seed));
        return array;
    }
    else if (ORDER == ASCEND)
    {
        for (int i = 0; i < size; i++)
        {
            *(array + i) = (i + 1);
        }
        return array;
    }
    else if (ORDER == DESCEND)
    {
        int j = size - 1;
        for (int i = 0; i < size; i++)
        {
            *(array + i) = j;
            --j;
        }
        return array;
    }
    else return nullptr;
}

// tests a given sort, reports time, swaps, etc. BIG BRAIN
void testSort(void (*sort)(int*, int), int* arr, int n){
    // chrono::start
    sort(arr, n);
    // chrono::end blah blah
    // output the diagnostic code
}
