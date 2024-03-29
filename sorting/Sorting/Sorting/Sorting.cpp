 

 
#include"pch.h"
#include<iostream>
#include<string>
#include<time.h>
#include<vector>
 
 
template<class Comparable>
void insertionsort(std::vector<Comparable> & a);

template<class Comparable>
void insertionsort(std::vector<Comparable> & a, int left, int right);

template<class Comparable>
void quicksort(std::vector<Comparable> & a);

template<class Comparable>
void quicksort(std::vector<Comparable> &a, int left, int right);

template<class Comparable>
const Comparable &median3(std::vector<Comparable> &a, int left, int right);

template<class Comparable>
void swap(int &num1, int &num2);

std::size_t n = 0;
std::size_t cutoff;
//bool flag=true; 
template<class Comparable>
void insertionsort(std::vector<Comparable> & a) {
	int co = 0;
	for (int p = 1; p < a.size(); p++) {
		int c = 0;
		Comparable tmp = a[p]; 

		int j; 
		for (j = p; j > 0 && tmp < a[j - 1]; j--) {
			a[j] = a[j - 1];  
			co++;
			c++;
		}
		a[j] = tmp;
		std::cout << "  After p = " << p << "  |  ";
		for (int i = 0; i < a.size(); i++) {

			std::cout << a[i] << "    ";
		}
		std::cout << "   " << c << std::endl;
	}
}

template<class Comparable>
void insertionsort(std::vector<Comparable> & a, int left, int right) {
	for (int p = left + 1; p <= right; p++) {
		Comparable tmp = a[p];
		int j;
		for (j = p; j > left&&tmp < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

template <class Comparable>
void quicksort(std::vector<Comparable> & a) {

	quicksort(a, 0, a.size() - 1);

}

template<class Comparable>
void quicksort(std::vector<Comparable> &a, int left, int right) {
	++n;
	if (left + cutoff <= right) {
		Comparable pivot = median3(a, left, right);
		int i = left, j = right - 1;
		for (;;) {
			while (a[++i] < pivot) {}
			while (a[--j] > pivot) {}
			if (i < j)
				std::swap(a[i], a[j]);

			else {
				break;
			}
		}
		std::swap(a[i], a[right - 1]);
		std::cout << "\n  Round " << n;

		for (int i = 0; i < a.size(); i++)
			std::cout << "    " << a[i];
		std::cout << std::endl;
		std::cout << "\n  Left = " << a[left] << "    Right = " << a[right] << "    Pivot = " << pivot << std::endl;
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}

	else {
		insertionsort(a, left, right);
		std::cout << "insertionsort" << std::endl;
		std::cout << "\n  Round " << n;

		for (int i = 0; i < a.size(); i++) {
			std::cout << "    " << a[i];
		}
		std::cout << "    No Pivot " << std::endl;
	}
}

template<class Comparable>
const Comparable &median3(std::vector<Comparable> &a, int left, int right) {
	int center = (left + right) / 2;
	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[right], a[center]);
	std::swap(a[center], a[right - 1]);

	return a[right - 1];
}

template<class Comparable>
void swap(int &num1, int &num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
#include"pch.h"
#include<iostream>
using namespace std;
 

void main() {

	vector<int> x(1);
	string choice;
	bool exit = true;
	bool create = false;
	clock_t t1, t2, t3, t4;

	do {
		system("cls");
		 cout << "\n\t\t\t===============================\n";
		cout << "\t\t\t.:: Assignment4 [ Sorting ] ::.\n";
		cout << "\t\t\t===============================\n";
		cout << "\t\t\t1.) Create Input";
		cout << "\n\t\t\t2.) Insertion Sort";
		cout << "\n\t\t\t3.) Quick Sort";
		cout << "\n\t\t\t4.) Exit";
		cout << "\n\t\t\t===============================";
		cout << "\n\n\t\t\tEnter Choice : ";
		cin >> choice;
		switch (choice[0])
		{
		case '1':
			system("cls");
			int num;
			 
		 
			cout << "\n      How many for input : ";
			cin >> num;
			cout << endl;
			x.resize(num);
		 
	 
			for (int i = 0; i < num; i++) {
				cout << "   Input Data [" << i << "] : ";
				cin >> x[i];
			}
			 
			create = !create;
			system("pause");
			break;
		case '2':
			system("cls");
			if (create)
			{
				cout << "\n\t\t\tInsertion Sort\n\n";
				cout << "  Original   " << "  |  ";
				for (int i = 0; i < num; i++)
				cout << x[i] << "    ";
				cout << "P.Moved\n";
				cout << "\n  ----------------------------------------------------------" << endl;
				t1 = clock();
				insertionsort(x);
				t2 = clock();
				cout << "\n  ----------------------------------------------------------" << endl;
				cout << "\nRunning Time : " << ((float)t2 - (float)t1) << " second\n" << endl;
				system("PAUSE");
			}
			else {
				cout << "\n\t\t\t!!!Must Insert before sort!!!\n\n";
				system("pause");
			}
			break;
		case '3':
			system("cls");
			if (create)
			{
				cout << "\n\t\tEnter Cutoff : ";
				cin >> cutoff;
				cout << "\n\t\tYour Cutoff is : " << cutoff << endl;
				cout << "\n\t\t\tQuick Sort\n\n";
				cout << "  Original   ";
				for (int i = 0; i < num; i++)
					cout << x[i] << "    ";
				cout << "\n  ----------------------------------------------------------" << endl;
				t3 = clock();
				quicksort(x, 0, num - 1);
				t4 = clock();
				cout << "\n  ----------------------------------------------------------" << endl;
				cout << "\n  Final      ";
				for (int i = 0; i < num; i++)
					 cout << x[i] << "    ";
				cout << endl;
				cout << "\nRunning Time : " << ((float)t4 - (float)t3) << " second\n" << endl;
				system("PAUSE");
			}
			else {
				cout << "\n\t\t\t!!!Must Insert before sort!!!\n\n";
				system("pause");
			}
			break;

		case '4':exit = false;
		}
	} while (exit);

}

 