// COSC320-002 Lab-1 (Dr. Anderson)
// Justin Ventura [helpers.cpp]

// Swapper
void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

// Bubble Sort (O(n^2))
void bubbleSort (int * arr, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

// Selection Sort (O(n^2))
void selectionSort (int * arr, int len)
{
	int i, j, min_index;
    for (i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}

// Insertion Sort (O(n^2))
void insertionSort (int * arr, int len)
{
	int i, j, sel;
    for (i = 1; i < len; i++)
    {
        sel = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > sel)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = sel;
    }
}

// Check if sorted
bool isSorted (int * arr, int len)
{
	int i;
	for (i = 1; i < len; i++)
		if (arr[i] < arr[i - 1])
			return false;

	return true;
}