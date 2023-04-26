// Task 1. Create a patient management system in the polyclinic. Each patient in the program is assigned a random number.
// The system should contain the following functions. After calling each function, the time for which it was performed should be displayed.
// The system should contain the following functions:
// 
//* 1. Creation, reductionand expansion of the list of patients.
// 2. Adding and removing a patient.
// 3. QuickSort and BogoSort sorting to choose from.
// 4. Patient search through binary and linear search.
// 5. Insertion of the patient on a certain index.Implement it iteratively and recursively.
// 6. Finding the largest and smallest index.Implement iteratively and recursively.
//

#include <iostream>
#include <stdio.h> 
#include <time.h> 
using namespace std;

void CreateArray(int list[], int size)
{
	for (int i = 0; i < size; i++)	// Filling empty array cells with the 0
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

void Add(int list[], int size, int in_index)
{
	list[0]++;
	list[list[0]] = in_index;
}

void MooveToPosition(int list[], int size, int pos)
{
	for (int i = list[0]; i != pos; --i)
	{
		swap(list[i], list[i - 1]);
	}
}

void Eraze()
{

}

int main()
{
	int size, menu;
	int pos;
	int in_index;

	cout << "\n\n\tEnter the list size: ";	cin >> size;
	size += 1;
	int* list = new int[size];	// Creating a custom size array

	CreateArray(list, size);

	do
	{
		OutputArray(list, size);
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

			for (int i = temp; i < new_size; i++)	// Filling empty array cells with the 0
				list[i] = 0;

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
					Add(list, size, in_index);

				break;
			case 2://Add to given position
				cout << "\n\t0 --Back\n\tEnter the index of new patient: "; cin >> in_index;
				if (in_index == 0)
					break;

				if (CheckList(list, size, in_index))
					Add(list, size, in_index);

				
				cout << "\n\tEnter patient position: ";	cin >> pos;

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
			default:
				break;
			}
		case 3://Delete patient
			cout << "\n\t0 --Back\n\tEnter the patient index to Eraze: "; cin >> in_index;
			if (in_index == 0)
				break;

		default:
			break;
		}
	} while (true);
	

}

