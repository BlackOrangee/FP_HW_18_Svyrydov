// Task 1. Create a patient management system in the polyclinic. Each patient in the program is assigned a random number.
// The system should contain the following functions. After calling each function, the time for which it was performed should be displayed.
// The system should contain the following functions:
// 
//[*] 1. Creation, reductionand expansion of the list of patients.
//[*] 2. Adding and removing a patient.
//[*] 3. QuickSort and BogoSort sorting to choose from.
//[*] 4. Patient search through binary and linear search.
//[*] 5. Insertion of the patient on a certain index.Implement it iteratively and recursively.
//[*] 6. Finding the largest and smallest index.Implement iteratively and recursively.
//

#include <iostream>
#include <stdio.h> 
#include <time.h> 
using namespace std;

void CreateArray(int list[], int size, int i, int size_);
void OutputArray(int list[], int size);
bool CheckList(int list[], int size, int in_index);
bool CheckList(int list[], int size, int in_index, int i);
void Add(int list[], int size, int in_index);
void MooveToPosition(int list[], int size, int pos);
void MooveToPosition(int list[], int size, int pos, int i);
void MooveToEnd(int list[], int size, int pos);
void Eraze(int list[], int size);
int BinarySearch(int list[], int size, int search);
int LinearSearch(int list[], int size, int search);
int Partition(int list[], int low, int high);
void QuickSort(int list[], int low, int high);
bool IsSorted(int list[], int size);
void Randomize(int list[], int size);
void BogoSort(int list[], int size);
int SmallestValue(int list[], int size);
int LargestValue(int list[], int size);

int main()
{
	int size, menu;
	int pos;
	int in_index;
	int search;

	cout << "\n\n\tEnter the list size: ";	cin >> size;
	size += 1;
	int* list = new int[size];	// Creating a custom size array

	clock_t start_time = clock();//Time func

	CreateArray(list, size, 0, size);//Creating array
	
	clock_t end_time = clock();//Time func
	double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "\n\tFunction execution time: " << time_taken << " sec\n";

	do
	{
		OutputArray(list, size);//Show array
		
		cout << "\n\t1 -- Resize list\n\t2 -- Add new patient\n\t3 -- Delete patient\n\t4 -- Sort\n\t5 -- Search\n\t";	cin >> menu;

		switch (menu)
		{
		case 1://Resize list
			int new_size;

			cout << "\n\t0 -- Back\n\tCurent list size is " << size - 1 << " patients";
			cout << "\n\tEnter the new size: "; cin >> new_size;

			if (new_size == 0)
				break;

			int temp;
			temp = size;
			size = new_size + 1;
			CreateArray(list, size, temp, new_size);

			break;
		case 2://Add new patient
			cout << "\n\t0 --Back\n\t1 -- Add to the end\n\t2 -- Add to given position\n\t";	cin >> menu;

			if (menu == 0)
				break;

			switch (menu)
			{
			case 1://Add to the end
				cout << "\n\t0 --Back\n\tEnter the index of new patient: "; cin >> in_index;
				if (in_index == 0)
					break;
				if (CheckList(list, size, in_index))
				{
					Add(list, size, in_index);
				}
				
				break;
			case 2://Add to given position

				cout << "\n\t0 -- Back\n\t1 -- Iteratively\n\t2 -- Recursively\n\t"; cin >> menu;
				if (menu == 0)
					break;

				switch (menu)
				{
				case 1://Iteratively
					cout << "\n\t0 -- Back\n\tEnter the index of new patient: "; cin >> in_index;
					if (in_index == 0)
						break;

					cout << "\n\tEnter patient position: ";	cin >> pos;

					if (CheckList(list, size, in_index))
						Add(list, size, in_index);

					if ((pos <= size) && (pos != 0))	// Swap and insert into position
					{
						MooveToPosition(list, size, pos);
					}
					else // Error
					{
						cout << "\n\tOut of size";
						break;
					}
					break;
				case 2://Recursively
					cout << "\n\t0 -- Back\n\tEnter the index of new patient: "; cin >> in_index;
					if (in_index == 0)
						break;

					cout << "\n\tEnter patient position: ";	cin >> pos;

					if (CheckList(list, size, in_index, 1))
						Add(list, size, in_index);

					if ((pos <= size) && (pos != 0))	// Swap and insert into position
					{
						MooveToPosition(list, size, pos, list[0]);
					}
					else // Error
					{
						cout << "\n\tOut of size";
						break;
					}
					break;
				default:
					break;
				}
				
				break;
			default:
				break;
			}
			break;
		case 3://Delete patient
			cout << "\n\t0 --Back\n\tEnter the patient index to Eraze: "; cin >> in_index;
			if (in_index == 0)
				break;


			if (LinearSearch(list, size, in_index))
			{
				MooveToEnd(list, size, LinearSearch(list, size, in_index));
				Eraze(list, size);
			}


			break;
		case 4://Sort
			cout << "\n\t0 -- Back\n\t1 -- Quick Sort\n\t2 -- Bogo Sort\n\t";	cin >> menu;
			if (menu == 0)
				break;
			switch (menu)
			{
			case 1://Quick Sort

				QuickSort(list, 1, list[0]);

				break;
			case 2://Bogo Sort

				BogoSort(list, list[0]);

				break;
			default:
				break;
			}
			break;
		case 5://Search
			cout << "\n\t0 --Back\n\t1 -- Linear search\n\t2 -- Binary search\n\t3 -- Largest value\n\t4 -- Smallest value\n\t"; cin >> menu;
			if (menu == 0)
				break;

			switch (menu)
			{
			case 1:	// Linear search
				cout << "\n\t0 -- Back\n\tEnter a patient index: "; cin >> search;
				if (search == 0)
					break;


				if (LinearSearch(list, size, search))
				{
					cout << "\n\tThe patient " << search << " in position " << LinearSearch(list, size, search);
				}


				break;
			case 2:	// Binary search
				cout << "\n\t0 -- Back\n\tEnter a patient index: "; cin >> search;
				if (search == 0)
					break;


				if (BinarySearch(list, size, search))
				{
					cout << "\n\tThe patient " << search << " in position " << BinarySearch(list, size, search);
				}
				break;
			case 3://largest value
				cout << "\n\tthe largest value in list: " << LargestValue(list, list[0]);
				break;
			case 4://Smallest value
				cout << "\n\tthe smallest value in list: " << SmallestValue(list, list[0]);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	} while (true);
}


void CreateArray(int list[], int size, int i, int size_)
{
	for (; i < size_; i++)	// Filling empty array cells with the 0
	{
		list[i] = 0;
	}
}

void OutputArray(int list[], int size)
{
	cout << "\n\n\tlist: ";
	for (int i = 1; i < size; i++)	// Array Output
	{
		cout << list[i];
		cout << " ";
	}
	cout << "\n\n\n";
}


bool CheckList(int list[], int size, int in_index)
{
	for (int i = 1; i < size; i++) // Checking if a patient exists in an array
	{
		if (list[i] == in_index)
		{
			cout << "\n\tpatient is alredy added";
			return false;
		}
	}
	return true;
}

bool CheckList(int list[], int size, int in_index, int i)
{
	if (i == size)
	{
		return true;
	}
	else if (list[i] == in_index)
	{
		cout << "\n\tpatient is alredy added";
		return false;
	}
	CheckList(list, size, in_index, ++i);
}

void Add(int list[], int size, int in_index)
{
	list[0]++;
	list[list[0]] = in_index;
}

void MooveToPosition(int list[], int size, int pos)
{
	clock_t start_time = clock();
	for (int i = list[0]; i != pos; --i)
	{
		swap(list[i], list[i - 1]);
	}
	clock_t end_time = clock();
	double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "\n\tFunction execution time: " << time_taken << " sec\n";
}

void MooveToPosition(int list[], int size, int pos, int i)
{
	if (i == pos)
	{
		return;
	}
	swap(list[i], list[i - 1]);

	MooveToPosition(list, size, pos, --i);
}

void MooveToEnd(int list[], int size, int pos)
{
	for (int i = pos; i != list[0]; i++)
	{
		swap(list[i], list[i + 1]);
	}
}

void Eraze(int list[], int size)
{
	list[list[0]] = 0;
	list[0]--;
}

int BinarySearch(int list[], int size, int search)
{
	int lo = 1;
	int hi = size - 1;
	int mid;

	while ((hi - lo) > 1)
	{
		mid = (hi + lo) / 2;
		if (list[mid] < search)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	if (list[lo] == search)
	{
		return lo;
	}
	else if (list[hi] == search)
	{
		return hi;
	}
	else
	{
		cout << "\n\tThe patient " << search << " not found\n";
		return 0;
	}
}

int LinearSearch(int list[], int size, int search)
{
	for (int i = 1; i < size; i++)
	{
		if (list[i] == search)
		{
			return i;
		}
	}
	cout << "\n\tThe patient " << search << " not found\n";
	return 0;
}

int Partition(int list[], int low, int high)
{
	int pivot = list[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (list[j] < pivot)
		{
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i + 1], list[high]);
	return (i + 1);
}

void QuickSort(int list[], int low, int high)
{
	clock_t start_time = clock();

	if (low < high)
	{
		int pi = Partition(list, low, high);
		QuickSort(list, low, pi - 1);
		QuickSort(list, pi + 1, high);
	}
	clock_t end_time = clock();
	double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "\n\tFunction execution time: " << time_taken << " sec\n";

}

bool IsSorted(int list[], int size)
{
	for (int i = size; i != 1; --i)
	{
		if (list[i] < list[i - 1])
		{
			return false;
		}
	}
	return true;
}

void Randomize(int list[], int size)
{
	for (int i = 1; i <= size; i++)
		swap(list[i], list[rand() % size]);
}

void BogoSort(int list[], int size)
{
	clock_t start_time = clock();

	while (!IsSorted(list, size))
		Randomize(list, size);

	clock_t end_time = clock();
	double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "\n\tFunction execution time: " << time_taken << " sec\n";
}

int SmallestValue(int list[], int size)
{
	clock_t start_time = clock();

	int lo = list[1];
	for (int i = 1; i <= size; i++)
	{
		if (lo > list[i])
		{
			lo = list[i];
		}
	}
	clock_t end_time = clock();
	double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "\n\tFunction execution time: " << time_taken << " sec\n";
	return lo;
}
int LargestValue(int list[], int size)
{
	clock_t start_time = clock();

	int hi = list[1];
	for (int i = 1; i <= size; i++)
	{
		if (hi < list[i])
		{
			hi = list[i];
		}
	}
	clock_t end_time = clock();
	double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "\n\tFunction execution time: " << time_taken << " sec\n";
	return hi;
}
