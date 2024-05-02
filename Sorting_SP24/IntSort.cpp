#include "IntSort.h"
#include <thread>

using namespace std;

IntSort::IntSort()
{
}

IntSort::~IntSort()
{
}

void IntSort::SelectionSort(int* list, int listSize)
{
	int lowIndex = 0;
	int temp, tempIndex;

	while (lowIndex < listSize - 1)
	{
		temp = list[lowIndex];
		tempIndex = lowIndex;

		for (int i = lowIndex + 1; i < listSize; i++)
		{
			if (list[i] < temp)
			{
				temp = list[i];
				tempIndex = i;
			}
		}

		list[tempIndex] = list[lowIndex];
		list[lowIndex] = temp;
		lowIndex++;
	}
}

void IntSort::BubbleSort(int* list, int listSize)
{
	int lowIndex = 0;
	int temp;

	while (lowIndex < listSize - 1)
	{
		temp = list[listSize - 1];

		for (int i = listSize - 2; i >= lowIndex; i--)
		{
			if (list[i] > temp)
			{
				list[i + 1] = list[i];
				list[i] = temp;
			}
			temp = list[i];
		}

		lowIndex++;
	}
}

void IntSort::InsertionSort(int* list, int listSize)
{
	int temp;
	int index;
	bool finished;

	for (int i = 1; i < listSize; i++)
	{
		index = i - 1;
		finished = false;

		while (index >= 0 && !finished)
		{
			if (list[index + 1] < list[index])
			{
				temp = list[index + 1];
				list[index + 1] = list[index];
				list[index] = temp;
				index--;
			}
			else
				finished = true;
		}
	}
}

void IntSort::MergeSort(int* list, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(list, first, mid);

		MergeSort(list, mid + 1, last);

		int leftFirst = first;
		int rightFirst = mid + 1;
		int leftLast = mid;
		int rightLast = last;
		int index = 0;

		int* temp = (int*)malloc(sizeof(int) * (last - first) + 1);//new int[(last - first) + 1];

		if (temp) {
			while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
			{
				if (list[leftFirst] < list[rightFirst])
				{
					temp[index] = list[leftFirst];
					leftFirst++;
				}
				else
				{
					temp[index] = list[rightFirst];
					rightFirst++;
				}
				index++;
			}

			while (leftFirst <= leftLast)
			{
				temp[index] = list[leftFirst];
				leftFirst++;
				index++;
			}

			while (rightFirst <= rightLast)
			{
				temp[index] = list[rightFirst];
				rightFirst++;
				index++;
			}

		
			for (int i = 0; i < (last - first) + 1; i++)
			{
				list[first + i] = temp[i];
			}
		}
		free(temp);
	}
}

void IntSort::ParallelMergeSort(int* list, int first, int last, int chunkSize)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		if (last - first > chunkSize)
		{
			thread left(&IntSort::ParallelMergeSort, this, list, first, mid, chunkSize);
			thread right(&IntSort::ParallelMergeSort, this, list, mid + 1, last, chunkSize);

			left.join();
			right.join();
		}
		else
		{
			MergeSort(list, first, mid);
			MergeSort(list, mid + 1, last);
		}

		int leftFirst = first;
		int rightFirst = mid + 1;
		int leftLast = mid;
		int rightLast = last;
		int index = 0;

		int* temp = (int*)malloc(sizeof(int) * (last - first) + 1);//new int[(last - first) + 1];

		if (temp) {
			while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
			{
				if (list[leftFirst] < list[rightFirst])
				{
					temp[index] = list[leftFirst];
					leftFirst++;
				}
				else
				{
					temp[index] = list[rightFirst];
					rightFirst++;
				}
				index++;
			}

			while (leftFirst <= leftLast)
			{
				temp[index] = list[leftFirst];
				leftFirst++;
				index++;
			}

			while (rightFirst <= rightLast)
			{
				temp[index] = list[rightFirst];
				rightFirst++;
				index++;
			}

			for (int i = 0; i < (last - first) + 1; i++)
			{
				list[first + i] = temp[i];
			}
		}
		free(temp);
	}
}