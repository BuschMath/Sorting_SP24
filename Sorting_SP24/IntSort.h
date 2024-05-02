#ifndef INTSORT_H
#define INTSORT_H

class IntSort
{
public:
	IntSort();
	~IntSort();

	void SelectionSort(int* list, int listSize);
	void BubbleSort(int* list, int listSize);
	void InsertionSort(int* list, int listSize);
	void MergeSort(int* list, int first, int last);
	void ParallelMergeSort(int* list, int first, int last, int chunkSize);

private:

};

#endif // !INTSORT_H

