// Author: Suzana Majcunic
// Program: Entering the list of numbers, applying the sort algorithm (bubble, shell, insertion or selection sort)
// and searching the specific element from sorted list.

#include "pch.h"
#include <iostream>
using namespace std;

void bubbleSort(int listNumbers[], int arraySize) 
{
	int i, j, temp;
	for (i = (arraySize - 1); i >= 0; i--) 
	{
		for (j = 1; j <= i; j++) {
			if (listNumbers[j - 1] > listNumbers[j]) 
			{
				temp = listNumbers[j - 1];
				listNumbers[j - 1] = listNumbers[j];
				listNumbers[j] = temp;
			}
		}
	}
}

void shellSort(int listNumbers[], int arraySize) 
{
	int j, i, k, m, mid;
	for (m = arraySize / 2; m > 0; m /= 2) 
	{
		for (j = m; j < arraySize; j++) 
		{
			for (i = j - m; i >= 0; i -= m) 
			{
				if (listNumbers[i + m] >= listNumbers[i])
					break;
				else 
				{
					mid = listNumbers[i];
					listNumbers[i] = listNumbers[i + m];
					listNumbers[i + m] = mid;
				}
			}
		}
	}
}

void insertionSort(int listNumbers[], int arraySize)
{
	int i, k, y;
	for (k = 1; k < arraySize; k++) 
	{
		y = listNumbers[k];
		for (i = k - 1; i >= 0 && y < listNumbers[i]; i--) 
		{
			listNumbers[i + 1] = listNumbers[i];
		}
		listNumbers[i + 1] = y;
	}
}

void selectionSort(int listNumbers[], int arraySize)
{
	int small, pos, tmp, i, j;
	for (i = 0; i < arraySize; i++) 
	{
		small = listNumbers[i];
		pos = i;
		for (j = i + 1; j < arraySize; j++) 
		{
			if (listNumbers[j] < small)
			{
				small = listNumbers[j];
				pos = j;
			}
		}
		tmp = listNumbers[i];
		listNumbers[i] = listNumbers[pos];
		listNumbers[pos] = tmp;
	}
}

int binarySearch(int listNumbers[], int element, int left, int right) 
{
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (listNumbers[middle] == element)
			return middle;
		else if (listNumbers[middle] > element)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}

int main()
{
	int arraySize, i, sortChoice, element;
	cout << "How many numbers do you want to enter in a sequence: ";
	cin >> arraySize;
	cout << endl;
	int *listNumbers = new int[arraySize];

	for (i = 0; i < arraySize; i++) 
	{
		cout << "Enter " << i + 1 << ". element of sequence: ";
		cin >> listNumbers[i];
	}
	cout << endl;

	cout << "Print of unsorted sequence: " << endl;
	for (i = 0; i < arraySize; i++) 
	{
		cout << listNumbers[i] << " ";
	}
	cout << endl << endl;

	do {
		cout << "Which sort method do you want to apply?" << endl << endl;
		cout << "1. Bubble Sort" << endl;
		cout << "2. Shell Sort" << endl;
		cout << "3. Insertion Sort" << endl;
		cout << "4. Selection Sort" << endl << endl;
		cout << "Your choice (1,2,3,4): ";
		cin >> sortChoice;
		cout << endl;
		switch (sortChoice) {
		case 1:	bubbleSort(listNumbers, arraySize);
			break;
		case 2:	shellSort(listNumbers, arraySize);
			break;
		case 3:	insertionSort(listNumbers, arraySize);
			break;
		case 4:	selectionSort(listNumbers, arraySize);
			break;
		default:cout << "Wrong entry! Please enter one of the offered choices!" << endl << endl;
			break;
		}
	} while ((sortChoice < 1) || (sortChoice > 4));

	cout << "Print of sorted sequence: " << endl;
	for (i = 0; i < arraySize; i++) 
	{
		cout << listNumbers[i] << " ";
	}
	cout << endl << endl;

	cout << "Which element are you looking for: ";
	cin >> element;
	cout << endl;

	int searchResult = binarySearch(listNumbers, element, 0, arraySize - 1);
	if (searchResult == -1) 
	{
		cout << "The function returned the result -1 which means the requested element was not found!" << endl;
	}
	else 
	{
		cout << "The searched element is placed at position sequence[" << searchResult << "] as a " << searchResult+1 << ". element." << endl;
	}
}


